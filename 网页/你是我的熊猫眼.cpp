<!doctype html>
<html lang="en">
 <head>
  <meta charset="UTF-8">
  <meta name="Generator" content="EditPlus®">
  <meta name="Author" content="">
  <meta name="Keywords" content="">
  <meta name="Description" content="">
  <style type="text/css">
	body {
  margin: 0;
}
canvas {
  cursor: none;
  display: block;
  margin: auto;
}
  </style>
  <title>Document</title>
 </head>
 <body>
<canvas></canvas>
  <script src="https://code.jquery.com/jquery-3.2.1.min.js"></script>
  <div id="jsi-particle-container" class="container"></div>
  <script type="text/javascript">
	window.requestAnimFrame = (function(){
  return window.requestAnimationFrame || 
      window.webkitRequestAnimationFrame || 
      window.mozRequestAnimationFrame || 
      window.oRequestAnimationFrame ||
      window.msRequestAnimationFrame ||
        function(callback){
          window.setTimeout(callback, 1000 / 60);
        };
})();
window.addEventListener("load",app);

function app() {
  var canvas = document.getElementsByTagName("canvas")[0];
  
  if (canvas.getContext) {
    var ctx = canvas.getContext("2d"),
		adjCanvas = function() {
			let w = window.innerWidth,
				h = window.innerHeight,
				s = 2;

			// adjust canvas to be retina-friendly
			canvas.width = w * s;
			canvas.height = h * s;
			canvas.style.width = w + "px";
			canvas.style.height = h + "px";
			ctx.scale(s,s);
		},
		rand = function(min, max) {
			return Math.floor(Math.random() * ((max + 1) - min)) + min;
		},
		randFloat = function(min, max) {
			return (Math.random() * ((max + 1) - min)) + min;
		},
		csr = {
			pos: {
				x: window.innerWidth/2,
				y: window.innerHeight/2
			},
			rad: 50,
			particle: function(x,y,r,op) {
				this.x = x;
				this.xS = this.x;
				// -1 = left, 0 = center, 1 right
				this.xDir = rand(-1,1);
				this.xSpeed = +Math.random().toFixed(1);
				this.yDir = rand(-1,1);
				this.ySpeed = +Math.random().toFixed(1);
				this.y = y;
				this.yS = this.y;
				this.r = r;
				this.rS = this.r;
				this.op = op;
				this.fadeRvrs = true;
			},
			particles: [],
			maxParticles: 120,
			pRadMin: 25,
			pRadMax: 35,
			fadeSpeed: 0.03,
			maxOp: 0.5,
			// eye.dir: -1 = left/up, 0 = center, 1 right/down
			eye : {
				dir: {
					h: 0,
					v: 0
				},
				pos: {
					x: 0,
					y: 0,
					limit: 10
				},
				lid: {
					span: 20,
					pos: 20
				},
				r: 24,
				isBlinking: false,
				blinkChance: 0.006,
				blinkRvrs: false
			}
		},
		boundDiff = function(x,y,h,k,r) {
			let testX = Math.pow(x - h, 2),
				testY = Math.pow(y - k, 2),
				rad2 = Math.pow(r, 2),
				diff = (testX + testY) - rad2;
			
			return diff;
		},
		drawLine = function(x1,y1,x2,y2) {
			ctx.beginPath();
			ctx.moveTo(x1,y1);
			ctx.lineTo(x2,y2);
			ctx.stroke();
			ctx.closePath();
		};
	  
	for (let s = 0; s < csr.maxParticles; ++s) {
		csr.particles[s] = new csr.particle(rand(csr.pos.x - csr.rad,csr.pos.x + csr.rad),rand(csr.pos.y - csr.rad,csr.pos.y + csr.rad),rand(csr.pRadMin,csr.pRadMax),randFloat(0.1,csr.maxOp));
		
		if (boundDiff(csr.particles[s].x,csr.particles[s].y,csr.pos.x,csr.pos.y,csr.rad) > 0) {
			csr.particles[s].x = csr.pos.x;
			csr.particles[s].y = csr.pos.y;
		}
	}
	csr.particles.sort(function(a, b){
		return a.r - b.r;
	});

    var drawScreen = function() {
			ctx.clearRect(0,0,canvas.width,canvas.height);
			
			// render particles
			for (let p in csr.particles) {
				let partGrd = ctx.createRadialGradient(csr.particles[p].x,csr.particles[p].y,0,csr.particles[p].x,csr.particles[p].y, csr.particles[p].r);
				partGrd.addColorStop(0, "#000");
				partGrd.addColorStop(1, "transparent");
				ctx.fillStyle = partGrd;
				
				ctx.globalAlpha = csr.particles[p].op;
				ctx.beginPath();
				ctx.arc(csr.particles[p].x,csr.particles[p].y,csr.particles[p].r,0,Math.PI*2,false);
				ctx.fill();
				ctx.closePath();
				ctx.globalAlpha = 1;
				
				csr.particles[p].x += csr.particles[p].xSpeed * csr.particles[p].xDir;
				csr.particles[p].y += csr.particles[p].ySpeed * csr.particles[p].yDir;
				
				if (csr.particles[p].fadeRvrs) {
					csr.particles[p].op -= csr.fadeSpeed;
				} else {
					csr.particles[p].op += csr.fadeSpeed;
				}
				
				if (csr.particles[p].op >= csr.maxOp) {
					csr.particles[p].fadeRvrs = true;
				}
				
				if (csr.particles[p].op <= 0) {
					csr.particles[p].x = rand(csr.pos.x - csr.rad,csr.pos.x + csr.rad);
					csr.particles[p].y = rand(csr.pos.y - csr.rad,csr.pos.y + csr.rad);
					
					if (boundDiff(csr.particles[p].x,csr.particles[p].y,csr.pos.x,csr.pos.y,csr.rad) > 0) {
						csr.particles[p].x = csr.pos.x;
						csr.particles[p].y = csr.pos.y;
					}
					
					csr.particles[p].op = csr.fadeSpeed;
					csr.particles[p].fadeRvrs = false;
				}
			}
		
			/* render eye */
			let shadow = ctx.createRadialGradient(csr.pos.x,csr.pos.y,0,csr.pos.x,csr.pos.y,csr.rad);
			// outside shadow
			shadow.addColorStop(0, "#000");
			shadow.addColorStop(0.65, "#000");
			shadow.addColorStop(1, "transparent");
			ctx.fillStyle = shadow;
			ctx.beginPath();
			ctx.arc(csr.pos.x,csr.pos.y,csr.rad,0,Math.PI*2,false);
			ctx.fill();
			ctx.closePath();
		
			// direction
			if (csr.eye.dir.h == 1) {
				if (csr.eye.pos.x <= csr.eye.pos.limit) {
					++csr.eye.pos.x;
				}
			} else if (csr.eye.dir.h == -1) {
				if (csr.eye.pos.x >= -csr.eye.pos.limit) {
					--csr.eye.pos.x;
				}
			} else {
				if (csr.eye.pos.x < 0) {
					++csr.eye.pos.x;
				} else if (csr.eye.pos.x > 0) {
					--csr.eye.pos.x;
				}
			}
			if (csr.eye.dir.v == 1) {
				if (csr.eye.pos.y <= csr.eye.pos.limit) {
					++csr.eye.pos.y;
				}
			} else if (csr.eye.dir.v == -1) {
				if (csr.eye.pos.y >= -csr.eye.pos.limit) {
					--csr.eye.pos.y;
				}
			} else {
				if (csr.eye.pos.y < 0) {
					++csr.eye.pos.y;
				} else if (csr.eye.pos.y > 0) {
					--csr.eye.pos.y;
				}
			}
			
			let sphereGrd = ctx.createRadialGradient(csr.pos.x,csr.pos.y,0,csr.pos.x,csr.pos.y,csr.eye.r),
				eyeGrd = ctx.createRadialGradient(csr.pos.x + csr.eye.pos.x,csr.pos.y + csr.eye.pos.y,0,csr.pos.x,csr.pos.y,csr.eye.r),
				glareR = csr.eye.r/16;
			
			// white part
			sphereGrd.addColorStop(0, "#eee");
			sphereGrd.addColorStop(0.65, "#eee");
			sphereGrd.addColorStop(1, "#777");
			
			ctx.fillStyle = sphereGrd;
			ctx.beginPath();
			ctx.arc(csr.pos.x,csr.pos.y,csr.eye.r-1,0,Math.PI*2,false);
			ctx.fill();
			ctx.closePath();
		
			// lines
			ctx.strokeStyle = "#f00";
			ctx.lineWidth = glareR < 1 ? 1 : Math.floor(glareR);
			let eyePosX = csr.pos.x + csr.eye.pos.x/2,
				eyePosY = csr.pos.y + csr.eye.pos.y/2;
			
			drawLine(eyePosX - (csr.eye.r/2),eyePosY,eyePosX + (csr.eye.r/2),eyePosY);
			drawLine(eyePosX - (csr.eye.r*0.44),eyePosY - (csr.eye.r*0.18),eyePosX + (csr.eye.r*0.44),eyePosY + (csr.eye.r*0.18));
			drawLine(eyePosX - (csr.eye.r/3),eyePosY - (csr.eye.r/3),eyePosX + (csr.eye.r/3),eyePosY + (csr.eye.r/3));
			drawLine(eyePosX - (csr.eye.r*0.18),eyePosY - (csr.eye.r*0.44),eyePosX + (csr.eye.r*0.18),eyePosY + (csr.eye.r*0.44));
			drawLine(eyePosX + (csr.eye.r*0.18),eyePosY - (csr.eye.r*0.44),eyePosX - (csr.eye.r*0.18),eyePosY + (csr.eye.r*0.44));
			drawLine(eyePosX - (csr.eye.r*0.44),eyePosY + (csr.eye.r*0.18),eyePosX + (csr.eye.r*0.44),eyePosY - (csr.eye.r*0.18));
			drawLine(eyePosX + (csr.eye.r/3),eyePosY - (csr.eye.r/3),eyePosX - (csr.eye.r/3),eyePosY + (csr.eye.r/3));
			drawLine(eyePosX,eyePosY - (csr.eye.r/2),eyePosX,eyePosY + (csr.eye.r/2));

			// center
			eyeGrd.addColorStop(0, "#000");
			eyeGrd.addColorStop(0.13, "#000");
			eyeGrd.addColorStop(0.13, "#ff0");
			eyeGrd.addColorStop(0.24, "#ff0");
			eyeGrd.addColorStop(0.24, "#f00");
			eyeGrd.addColorStop(0.35, "#f00");
			eyeGrd.addColorStop(0.35, "transparent");
			ctx.fillStyle = eyeGrd;
			ctx.beginPath();
			ctx.arc(csr.pos.x,csr.pos.y,csr.eye.r,0,Math.PI*2,false);
			ctx.fill();
			ctx.closePath();
		
			ctx.fillStyle = "#fff";
			ctx.beginPath();
			ctx.arc(csr.pos.x+glareR,csr.pos.y-glareR,glareR,0,Math.PI*2,false);
			ctx.fill();
			ctx.closePath();
		
			// blink
			if (Math.random() < csr.eye.blinkChance && !csr.eye.isBlinking) {
				csr.eye.isBlinking = true;
			} else if (csr.eye.isBlinking) {
				if (csr.eye.blinkRvrs) {
					++csr.eye.lid.pos;
				} else {
					--csr.eye.lid.pos;
				}
				if (csr.eye.lid.pos === 0) {
					csr.eye.blinkRvrs = true;
				} else if (csr.eye.lid.pos == csr.eye.lid.span) {
					csr.eye.blinkRvrs = false;
					csr.eye.isBlinking = false;
				}
			}
			
			// upper lid
			ctx.fillStyle = "#000";
			ctx.beginPath();
			ctx.moveTo(csr.pos.x - csr.eye.r, csr.pos.y);
			ctx.arc(csr.pos.x,csr.pos.y,csr.eye.r,Math.PI,Math.PI*2,false);
      		ctx.quadraticCurveTo(csr.pos.x, csr.pos.y - csr.eye.lid.pos, csr.pos.x - csr.eye.r, csr.pos.y);
			ctx.fill();
			ctx.closePath();
		
			// lower lid
			ctx.beginPath();
			ctx.moveTo(csr.pos.x - csr.eye.r, csr.pos.y);
      		ctx.arc(csr.pos.x,csr.pos.y,csr.eye.r,Math.PI,Math.PI*2,true);
      		ctx.quadraticCurveTo(csr.pos.x, csr.pos.y + csr.eye.lid.pos, csr.pos.x - csr.eye.r, csr.pos.y);
			ctx.fill();
			ctx.closePath();
        },
        updatePos = function(e){
			let eX = e.pageX - this.offsetLeft,
				eY = e.pageY - this.offsetTop;

			// eye moving right/left
			if (eX > csr.pos.x) {
				csr.eye.dir.h = 1;
			} else if (eX < csr.pos.x) {
				csr.eye.dir.h = -1;
			} else {
				csr.eye.dir.h = 0;
			}
			
			// up/down
			if (eY > csr.pos.y) {
				csr.eye.dir.v = 1;
			} else if (eY < csr.pos.y) {
				csr.eye.dir.v = -1;
			} else {
				csr.eye.dir.v = 0;
			}

			csr.pos.x = eX;
			csr.pos.y = eY;
		},
        run = function(){
          drawScreen();
		  requestAnimFrame(run);
        };

	adjCanvas();
    run();

	window.addEventListener("resize", adjCanvas);

	// touch events
	if ("ontouchstart" in document.documentElement) {
		canvas.addEventListener("touchstart",updatePos);
		canvas.addEventListener("touchmove",updatePos);

		document.addEventListener("touchstart",function(e) {
		    e.preventDefault();
		});
	// mouse
	} else {
		canvas.addEventListener("mousemove",updatePos);
	}
  }
}
  </script>
 </body>
</html>
