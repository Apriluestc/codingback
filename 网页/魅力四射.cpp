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
  height: 100%;
}

body {
  margin: 0;
  padding: 0; 
  background-color: #000000;
  display: flex;

  /* This centers our sketch horizontally. */
  justify-content: center;

  /* This centers our sketch vertically. */
  align-items: center;
}

  </style>
  <title>Document</title>
 </head>
 <body>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/p5.js/0.5.7/p5.min.js"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/dat-gui/0.6.3/dat.gui.min.js"></script>
  <script src="https://code.jquery.com/jquery-3.2.1.min.js"></script>
  <div id="jsi-particle-container" class="container"></div>
  <script type="text/javascript">
	var parm = {
  saveImage: function() {
    saveCanvas();
  },
  freeze: function() {
    if (this.froze) loop();
    else noLoop();
    this.froze = !this.froze;
  }
};

var m1, w1, w2;
function setup() {
  createCanvas(800, 800);

  m1 = new ColorOrb({x:width/2, y:height/2, rotate_v:1/33, radius:200, points: 9, stroke:"f0f0f0"});
  w1 = new Orbit({pivotx:width/2, pivoty:height/2, rotate_v:1/33, radius: 200, osc_v:0.05, osc_min:25, points: 11,
    orb:{radius:45, points:6, rotate_v:1/22},
    });
  w2 = new Orbit({pivotx:width/2, pivoty:height/2, rotate_v:1/11, radius: 150,
    orb:{radius:5, points:3}, link:w1,
    });
  var gui = new dat.GUI();
  gui.add(parm, "saveImage").name("Save Image");
  gui.add(parm, "freeze").name("Freeze");
  gui.close();
}

function draw() {
// background(0);
      
blendMode(BLEND);
fill(0, 65);
noStroke();
rect(0, 0, width, height);

  //m1.draw();
  w1.draw();
  w2.draw();

}

class Orb {
	constructor (options) {
    	var options = options || {};
    	this.x = options.x || 0;
    	this.y = options.y || 0;
    	this.fill = options.fill || null;
    	this.stroke = options.stroke || "#ff0000";
    	this.radius = options.radius || 250;
    	this.points = options.points || 12;
    	this.rotate_v = options.rotate_v || 0.0; // 0.33


    	this.rotate = 0;
    	this.pxy = [];
	}

	draw() {
		  if (this.stroke) stroke(this.stroke);
		  if (this.fill) fill(this.fill);
		  this.rotate+= this.rotate_v;
		  this.build();
		  this.pxy.forEach(function(p1, i) {
		    this.pxy.forEach(function(p2, j) {
		      if (i!=j) line(p1.x, p1.y, p2.x, p2.y);
		    })
		  }, this)
	}

	build() {
  		this.pxy.length = 0; // clear array
  		var angle = TWO_PI / this.points;
  		for (var i = 0; i < this.points; i++) {
      		var px = cos( angle * i  + this.rotate) * this.radius;
      		var py = sin( angle * i  + this.rotate) * this.radius;
      		this.pxy[i] = {x:px+this.x, y:py+this.y};
  		}  
	}

}

class ColorOrb extends Orb {

	constructor(options) {
		super(options);
		this.cp = options.cp || 180;
		this.cd = options.cd || 100;
	}

	draw() {
		colorMode(HSB,360,100,100);
		this.rotate+= this.rotate_v;
		this.build();
		this.pxy.forEach(function(p1, i) {
		this.pxy.forEach(function(p2, j) {
	  		if (i!=j) {
				stroke(int(randomGaussian(this.cp,this.cd)), 100, 100);
	  			line(p1.x, p1.y, p2.x, p2.y);
	  		}
		}, this)
		}, this)
	colorMode(RGB, 255);
	}
}

class Orbit {
	constructor (options) {
    	var options = options || {};
    	this.pivotx = options.pivotx || 0;
    	this.pivoty = options.pivoty || 0;
    	this.fill = options.fill || null;
    	this.stroke = options.stroke || "#ff0000";
    	this.radius = options.radius || 200;
    	this.points = options.points || 6;
    	this.rotate_v = options.rotate_v || 0.0; // 0.33
    	this.osc_v = options.osc_v || 0;
    	this.osc_min = options.osc_min || 0.0;
    	this.osc_max = options.osc_max || this.radius;
    	this.orb = options.orb || {};
    	this.link = options.link || null;


    	this.rotate = 0;
    	this.osc = 0;
    	this.b = [];

    	this.build();
	}

	build() {
		for (var i=0; i < this.points; i++) {
			this.b[i] = new ColorOrb(this.orb);
		}
	}

	draw() {
  		this.rotate+= this.rotate_v;
  		this.osc+=this.osc_v;
  		if (this.osc!=0)
  			this.radius = map(sin(this.osc),-1,1,this.osc_min,this.osc_max);

  		if (this.link) { // draw monads around centers of another ring of monads..
  			for (var i=0; i<this.link.points; i++) {
  				this.drawOrbs(this.link.b[i].x, this.link.b[i].y);
  			}
  		}
  		else {
  			this.drawOrbs(this.pivotx, this.pivoty);
  		}
	}

	drawOrbs(x,y) {
  		var angle = TWO_PI / this.points;
  		for (var i = 0; i < this.points; i++) {
      		this.b[i].x = cos( angle * i  + this.rotate) * this.radius + x;
      		this.b[i].y = sin( angle * i  + this.rotate) * this.radius + y;
      		this.b[i].draw();
  		} 
	}

}


  </script>
 </body>
</html>
