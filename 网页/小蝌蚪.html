<!doctype html>
<html lang="en">
 <head>
  <meta charset="UTF-8">
  <meta name="Generator" content="EditPlus®">
  <meta name="Author" content="">
  <meta name="Keywords" content="">
  <meta name="Description" content="">
  <style type="text/css">
	html, body {
  width: 100%;
  height: 100%;
  overflow: hidden;
}
body {
  background: black;
}
p {
  color: white;
  position: absolute;
  text-align: center;
  bottom: 20px;
  width: 100%;
  font-size: 12px;
  font-family: Arial, sans-serif;
  animation: fadeInOut 800ms infinite alternate;
}
@keyframes fadeInOut {
  from { opacity: 0.3; }
  to { opacity: 0.7; }
}

  </style>
  <title>Document</title>
 </head>
 <body>
<p>Click to show/hide pendulum</p>
<!-- Then read and play with the JS, it's cool! -->
  <script src="https://code.jquery.com/jquery-3.2.1.min.js"></script>
  <div id="jsi-particle-container" class="container"></div>
  <script type="text/javascript">
	/**
 * JS for Elastic Pendulum
 * 
 * @author Alexandre Andrieux for SimplX <alexandre.andrieux@simplx.fr>, <alex@icosacid.com>
 * @CodePen @simplx @Icosacid
 * @since 2017-06-01
 *
 * How 'bout an elastic double pendulum?
 * Spring forces, gravity and viscositude, because viscosity is so yesterday!
 *
 * This pen is a derivation of a more complex pen collection about reproducing the concept of mesh with particles and trying to approach fluid-like behaviors. https://codepen.io/simplx/pen/peYywo
 * Inspired by this 9gag post https://9gag.com/gag/a6bdV6N and my previous pen about Inverse Kinematics https://codepen.io/Icosacid/pen/VbeyZO
 *
 * I always enjoy feedback! Cheers
 */

var App = {};

document.addEventListener("DOMContentLoaded", function(event) {
  // Setup canvas and app
  App.setup();
  // Launch animation loop
  App.frame = function() {
    App.update();
    window.requestAnimationFrame(App.frame);
  };
	App.frame();
});

App.setup = function() {
  // Setup canvas and get canvas context
  var canvas = document.createElement('canvas');
  canvas.height = window.innerHeight;
  canvas.width = window.innerWidth;
  canvas.id = 'ourCanvas';
  document.body.appendChild(canvas);
  this.ctx = canvas.getContext('2d');
  this.ctx.rect(0, 0, this.width, this.height);
  this.ctx.fillStyle = 'black';
  this.ctx.fill();
  this.width = canvas.width;
  this.height = canvas.height;
  
  // Add event liteners
  canvas.addEventListener('mousemove', function(event) {
    App.target.x = event.pageX;
    App.target.y = event.pageY;
  });
  canvas.addEventListener('mouseleave', function(event) {
    App.target = {
      x: App.xC,
      y: App.yC
    };
  });
  canvas.addEventListener('mousedown', function(event) {
    App.showArms = !App.showArms;
  });
  
  // Define a few useful elements
  this.stepCount = 0;
  this.xC = canvas.width / 2;
  this.yC = canvas.height / 2;
  this.target = {
    x: undefined,
    y: undefined
  };
  
  this.grid = [];
  this.h = 80;// Step size (px)
  this.gridXnodes = 0;
  this.gridYnodes = 0;
  
  this.springStiffnessBase = 40;
  this.springStiffness = this.springStiffnessBase;// Might be altered on the fly, huehuehuehue
  this.springLength = 80;// Default spring Length (no constraint)
  this.viscosity = 0.00001;
  this.viscositude = 0.00001;// Some kind of super viscosity I invented that will slow down particles based on their speed^3, helps prevent system explosion
  this.gravity = 2;
  this.tau = 0.7;
  this.pendulumInitialXspeed = 50;
  this.pendulumYdepth = 2;
  this.pendulumXdepth = 0;// Try playing with that one
  
  this.showArms = false;// Gets toggled on click
  
  // Release madness
  this.setupGrid(this.h);
};
App.setupGrid = function(h) {
  // Create some nodes, initially a squared mesh
  for (var x = 0.5 * this.width; x <= 0.5 * this.width + this.pendulumXdepth * h; x += h) {
    var col = [];
    for (var y = 0.4 * this.height; y <= 0.4 * this.height + this.pendulumYdepth * h; y += h) {
      var particle = {
        x: x,
        y: y,
        xLast: x,
        yLast: y,
        xSpeed: 0,
        ySpeed: 0,
        m: 250,
        hue: x * y / 100,
        fixed: false
      }
      col.push(particle);
    }
    // Set horizontal speed to bottommost particle
    col[col.length - 1].xSpeed = this.pendulumInitialXspeed;
    
    this.grid.push(col);
  }
  
  // Update grid node size
  this.gridXnodes = this.grid.length;
  this.gridYnodes = this.grid[0].length;
  
  // Stabilize some particles (fixed contraits)
  /*var leftWall = this.grid[0],
      rightWall = this.grid[this.grid.length - 1],
      bottomWall = [];
  for (var c = 0; c < this.grid.length; c++) {
    // Add last particle on the column (bottom)
    bottomWall.push(this.grid[c][this.grid[c].length - 1]);
  }
  var walls = _.union(leftWall, rightWall, bottomWall);*/
  var walls = [this.grid[0][0]];// Just the first particle (pendulum)
  _(walls).each(function(particle) {
    particle.fixed = true;
  });
};
App.update = function() {
  // Evolve system
  this.evolve();
  // Move particles
  this.move();
  // Draw particles
  this.draw();
};
App.evolve = function() {
  this.stepCount++;
  
  // Hahahaha this is not just a couple o'springs, but EVOLVING SPRINGS! Eww I'm so evil.
  this.springStiffness = this.springStiffnessBase * (2 + Math.sin(this.stepCount / 200));
};
App.birth = function() {
  // No one's born tho
  var particle = {
    x: this.width * Math.random(),
    y: this.height * (0.5 + 0.5 * Math.random()),
    xSpeed: 0,
    ySpeed: 0,
    name: 'seed' + this.stepCount
  };
  
  this.particles.push(particle);
};
App.kill = function(particleName) {
  // No one dies tho
 this.particles = _(this.particles).reject(function(seed) {
    return (seed.name == particleName);
  });
};
App.move = function() {
 for (var i = 0; i < this.grid.length; i++) {
    for (var j = 0; j < this.grid[0].length; j++) {
      var particle = this.grid[i][j];
      
      // Save previous position
      particle.xLast = particle.x;
      particle.yLast = particle.y;
      
      // Calculate forces from neighbours
      var particleWest = undefined,
          particleEast = undefined,
          particleNorth = undefined,
          particleSouth = undefined;
      var k = this.springStiffness,
          l = this.springLength;
      
      if (i > 0) {// Western neighbour
        particleWest = this.grid[i-1][j];
        var toWest = { x: particleWest.xLast - particle.x, y: particleWest.yLast - particle.y };
        var distWest = Math.sqrt(Math.pow(toWest.x, 2) + Math.pow(toWest.y, 2));
        var FwestAmp = this.springForce(distWest, l, k);
        var FwestAngle = segmentAngleRad(particle.x, particle.y, particleWest.xLast, particleWest.yLast, true);
        var FwestX = FwestAmp * Math.cos(FwestAngle);
        var FwestY = FwestAmp * Math.sin(FwestAngle);
      }
      if (i < this.grid.length - 1) {// Eastern neighbour
        particleEast = this.grid[i+1][j];
        var toEast = { x: particleEast.x - particle.x, y: particleEast.y - particle.y };
        var distEast = Math.sqrt(Math.pow(toEast.x, 2) + Math.pow(toEast.y, 2));
        var FeastAmp = this.springForce(distEast, l, k);
        var FeastAngle = segmentAngleRad(particle.x, particle.y, particleEast.xLast, particleEast.yLast, true);
        var FeastX = FeastAmp * Math.cos(FeastAngle);
        var FeastY = FeastAmp * Math.sin(FeastAngle);
      }
      if (j > 0) {
        particleNorth = this.grid[i][j-1];
        var toNorth = { x: particleNorth.xLast - particle.x, y: particleNorth.yLast - particle.y };
        var distNorth = Math.sqrt(Math.pow(toNorth.x, 2) + Math.pow(toNorth.y, 2));
        var FnorthAmp = this.springForce(distNorth, l, k);
        var FnorthAngle = segmentAngleRad(particle.x, particle.y, particleNorth.xLast, particleNorth.yLast, true);
        var FnorthX = FnorthAmp * Math.cos(FnorthAngle);
        var FnorthY = FnorthAmp * Math.sin(FnorthAngle);
      }
      if (j < this.grid[0].length - 1) {
        particleSouth = this.grid[i][j+1];
        var toSouth = { x: particleSouth.x - particle.x, y: particleSouth.y - particle.y };
        var distSouth = Math.sqrt(Math.pow(toSouth.x, 2) + Math.pow(toSouth.y, 2));
        var FsouthAmp = this.springForce(distSouth, l, k);
        var FsouthAngle = segmentAngleRad(particle.x, particle.y, particleSouth.xLast, particleSouth.yLast, true);
        var FsouthX = FsouthAmp * Math.cos(FsouthAngle);
        var FsouthY = FsouthAmp * Math.sin(FsouthAngle);
      }
      
      var Fx = (!!particleWest ? FwestX : 0) + (!!particleEast ? FeastX : 0) + (!!particleNorth ? FnorthX : 0) + (!!particleSouth ? FsouthX : 0);
      var Fy = (!!particleWest ? FwestY : 0) + (!!particleEast ? FeastY : 0) + (!!particleNorth ? FnorthY : 0) + (!!particleSouth ? FsouthY : 0);
     
      // Newton second law
      var xAcc = Fx / particle.m - this.viscosity * particle.xSpeed - this.viscositude * Math.pow(particle.xSpeed, 3);
      var yAcc = Fy / particle.m - this.viscosity * particle.ySpeed - this.viscositude * Math.pow(particle.ySpeed, 3) + this.gravity / particle.m;
      
      // Very complex integration
      particle.xSpeed += xAcc;
      particle.ySpeed += yAcc;
      
      // If the particle is not fixed, move!
      if (!particle.fixed) {
        particle.x += this.tau * particle.xSpeed;
        particle.y += this.tau * particle.ySpeed;
      }
      
      // Otherwise get controlled by user
      if (this.target.x && this.target.y && particle.fixed) {
        particle.x = this.target.x;
        particle.y = this.target.y;
      }
      
    }
  }
  
};
App.draw = function() {
  // Add thin transparent layer to canvas (trace effect)
  this.ctx.beginPath();
  this.ctx.rect(0, 0, this.width, this.height);
  this.ctx.fillStyle = 'rgba(0, 0, 0, 0.06)';
  this.ctx.fill();
  
  // Draw particles
  for (var i = 0; i < this.grid.length; i++) {
    for (var j = 0; j < this.grid[i].length; j++) {
      var particle = this.grid[i][j];
      
      // Draw arms and all
      if (this.showArms && (j != this.grid[0].length - 1)) {
        this.ctx.strokeStyle = 'rgba(255, 255, 255, 0.1)';
        this.ctx.fillStyle = 'rgba(255, 255, 255, 0.5)';
        this.ctx.lineWidth = 2;
        
        if (i > 0) {
          var particleWest = this.grid[i-1][j];
          this.ctx.beginPath();
          this.ctx.moveTo(particle.x, particle.y);
          this.ctx.lineTo(particleWest.x, particleWest.y);
          this.ctx.stroke();
        }
        if (i < this.grid.length - 1) {
          var particleEast = this.grid[i+1][j];
          this.ctx.beginPath();
          this.ctx.moveTo(particle.x, particle.y);
          this.ctx.lineTo(particleEast.x, particleEast.y);
          this.ctx.stroke();
        }
        if (j > 0) {
          var particleNorth = this.grid[i][j-1];
          this.ctx.beginPath();
          this.ctx.moveTo(particle.x, particle.y);
          this.ctx.lineTo(particleNorth.x, particleNorth.y);
          this.ctx.stroke();
        }
        if (j < this.grid[0].length - 1) {
          var particleSouth = this.grid[i][j+1];
          this.ctx.beginPath();
          this.ctx.moveTo(particle.x, particle.y);
          this.ctx.lineTo(particleSouth.x, particleSouth.y);
          this.ctx.stroke();
        }
        
        // Draw particle with $1000000 special effects
        this.ctx.beginPath();
        this.ctx.arc(particle.x, particle.y, 5, 0, 2 * Math.PI, false);
        this.ctx.fill();
        this.ctx.beginPath();
        this.ctx.arc(particle.x, particle.y, 5, 0, 2 * Math.PI, false);
        this.ctx.fillStyle = 'hsla(' + 190 + ', 100%, 100%, 0.1)';
        this.ctx.fill();
        this.ctx.beginPath();
        this.ctx.arc(particle.x, particle.y, 2, 0, 2 * Math.PI, false);
        this.ctx.fillStyle = 'hsla(' + 180 + ', 100%, 100%, 0.5)';
        this.ctx.fill();
      }
      
      // If it's last particle on the column, draw special color 
      if (j == this.grid[0].length - 1) {
        this.ctx.save();
        this.ctx.shadowBlur = 5;
        this.ctx.shadowColor = 'hsla(' + 200 + ', 100%, 60%, 1)';
        this.ctx.beginPath();
        this.ctx.arc(particle.x, particle.y, 10, 0, 2 * Math.PI, false);
        this.ctx.fillStyle = 'hsla(' + 220 + ', 80%, 50%, 0.2)';
        this.ctx.fill();
        this.ctx.beginPath();
        this.ctx.arc(particle.x, particle.y, 5, 0, 2 * Math.PI, false);
        this.ctx.fillStyle = 'hsla(' + 190 + ', 90%, 60%, 0.6)';
        this.ctx.fill();
        this.ctx.beginPath();
        this.ctx.arc(particle.x, particle.y, 2, 0, 2 * Math.PI, false);
        this.ctx.fillStyle = 'hsla(' + 180 + ', 100%, 75%, 1)';
        this.ctx.fill();
        this.ctx.restore();
      }
    }
    
  }
};
App.springForce = function(dist, l, k) {
  // dist is the distance between two vertices bound by a spring, l is the natural spring length, k is spring stiffness
  var force = 0;
  if (dist < l/2) {
    var lambda = k * l * l / 4;
    force = -lambda / dist;
  } else {
    force = k * (dist - l);
  }
  
  // Protect against system explosion (kinda)
  return Math.min(Math.max(force, -1000), 1000);
}

/**
 * Some cool helper I wrote a few years ago
 * 
 * @param {Number} Xstart X value of the segment starting point
 * @param {Number} Ystart Y value of the segment starting point
 * @param {Number} Xtarget X value of the segment target point
 * @param {Number} Ytarget Y value of the segment target point
 * @param {Boolean} realOrWeb true if Real (Y towards top), false if Web (Y towards bottom)
 * @returns {Number} Angle between 0 and 2PI
 */
segmentAngleRad = function(Xstart, Ystart, Xtarget, Ytarget, realOrWeb) {
	var result;// Will range between 0 and 2PI
	if (Xstart == Xtarget) {
		if(Ystart == Ytarget) {
			result = 0; 
		} else if (Ystart < Ytarget) {
			result = Math.PI/2;
		} else if (Ystart > Ytarget) {
			result = 3*Math.PI/2;
		} else {}
	} else if (Xstart < Xtarget) {
		result = Math.atan((Ytarget - Ystart)/(Xtarget - Xstart));
	} else if (Xstart > Xtarget) {
		result = Math.PI + Math.atan((Ytarget - Ystart)/(Xtarget - Xstart));
	}
	
	result = (result + 2*Math.PI)%(2*Math.PI);
	
	if (!realOrWeb) {
		result = 2*Math.PI - result;
	}
	
	return result;
}

  </script>
 </body>
</html>
