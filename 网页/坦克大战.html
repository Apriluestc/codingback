<!doctype html>
<html lang="en">
 <head>
  <meta charset="UTF-8">
  <meta name="Generator" content="EditPlus®">
  <meta name="Author" content="">
  <meta name="Keywords" content="">
  <meta name="Description" content="">
  <style type="text/css">
	html,
body {
	background: black;
	margin: 0;
	overflow: hidden;
	color: white;
	font-family: monospace;
}

#instructions {
	position: absolute;
	top: 20px;
	left: 20px;
}

  </style>
  <title>Document</title>
 </head>
 <body>
#instructions
	div Press W/A to move
	div Press S/D to rotate tank
	div Press E/Q to rotate turret
	div Press [Space] to fire
  <script src="https://code.jquery.com/jquery-3.2.1.min.js"></script>
  <div id="jsi-particle-container" class="container"></div>
  <script type="text/javascript">
	let canvas, ctx;

let autoDrive = /fullcpgrid/.test(location.pathname);
let tanks = [];

function setup() {
	canvas = createCanvas(windowWidth, windowHeight);
	ctx = canvas.drawingContext;
	
	colorMode(HSB);
	
	let count = 6;
	for(let i = 0; i < count; i++) {
		let t = i / count * TAU;
		let tank = new Tank();
		let o = createVector(tank.body.size.w * 2.5, 0).rotate(t);
		tank.body.pos.add(o);
		tank.body.angle = t;
		tanks.push(tank);
	}
	
	background(51);
}

function draw() {
	// background(0);
	
	fill(0, 0.025);
	noStroke();
	rect(0, 0, width, height);
	
	stroke(255);
	noFill();
	
	translate(width / 2, height / 2);
	
	tanks.forEach(tank => {
		if(keyIsDown(87) || (autoDrive && frameCount < 40)) {
			tank.move(1);
		}
		if(keyIsDown(83) || (autoDrive && frameCount >= 80)) {
			tank.move(-1);
		}
		if(keyIsDown(65) || (autoDrive && frameCount < 50)) {
			tank.rotate(-1);
		}
		if(keyIsDown(68) || (autoDrive && frameCount > 60)) {
			tank.rotate(1);
		}
		if(keyIsDown(81)) {
			tank.turret.rotate(-1);
		}
		if(keyIsDown(69) || (autoDrive && frameCount % 2 === 0)) {
			tank.turret.rotate(1);
		}
		if(keyIsDown(32) || (autoDrive && frameCount > 20)) {
			tank.fire();
		}
		tank.draw();
	});
}

function windowResized() {
	resizeCanvas(windowWidth, windowHeight);
	background(51);
}

class TankChassis {
	constructor() {
		this.angle = 0;
		this.size = { w: 10, l: 10 };
		this.rotSpeed = 1;
	}
	
	draw() {
		rect(
			-this.size.w / 2,
			-this.size.l / 2,
			this.size.w,
			this.size.l
		);
	}
	
	rotate(direction = 1) {
		this.angle += TAU / 360 * this.rotSpeed * direction;
	}
}

class TankBody extends TankChassis {
	constructor() {
		super();
		this.pos = createVector(0, 0);
		this.angle = PI;
		this.size = { w: 50, l: 100 };
		this.speed = 1;
	}
	
	move(direction = 1) {
		let movement = this.speed * direction;
		let vector = createVector(0, movement)
				.rotate(this.angle);
		this.pos.add(vector);
	}
	
	draw() {
		super.draw();
		rect(
			-this.size.w / 2,
			this.size.l / 2 * 0.85,
			this.size.w,
			this.size.l / 10
		);
	}
}

class TankBullet {
	constructor(pos, angle = 0, speed = 5) {
		this.created = Date.now();
		this.ageLimit = 10000;
		this.pos = pos.copy() || createVector(0, 0);
		this.angle = angle;
		this.speed = speed;
		this.size = { d: 3, l: 5 };
	}
	
	update() {
		let vector = createVector(0, this.speed)
				.rotate(this.angle);
		this.pos.add(vector);
	}
	
	draw() {
		push();
		
		translate(this.pos.x, this.pos.y);
		rotate(this.angle);
		
		rect(
			-this.size.d / 2,
			-this.size.l / 2,
			this.size.d,
			this.size.l
		);
		
		pop();
	}
}

class TankGun extends TankChassis {
	constructor() {
		super();
		this.size = { w: 5, l: 60 };
		this.bullets = [];
		this.lastFired = 0;
		this.coolDown = 100;
	}
	
	fire(...args) {
		let now = Date.now();
		if(now < this.lastFired + this.coolDown) {
			return false;
		}
		this.lastFired = Date.now();
		let bullet = new TankBullet(...args);
		this.bullets.push(bullet);
		return bullet;
	}
}

class TankTurret extends TankChassis {
	constructor() {
		super();
		this.size = { w: 40, l: 70 };
		this.rotSpeed = 1;
		this.gun = new TankGun();
	}
	
	draw() {
		super.draw();
		
		push();
		
		translate(0, this.size.l / 3 + this.gun.size.l / 2);
		
		this.gun.draw();
		
		pop();
	}
	
	drawBullets() {
		let now = Date.now();
		noStroke();
		this.gun.bullets.forEach((bullet, i) => {
			fill(bullet.created / 6 % 360, 100, 100, 1 - (now - bullet.created) / bullet.ageLimit);
			bullet.draw();
			if(
				(
					bullet.pos.x > width / 2 ||
					bullet.pos.x < -width / 2 || 
					bullet.pos.y > height / 2 ||
					bullet.pos.y < -height / 2
				) &&
				bullet.created + bullet.ageLimit < now
			) {
				this.gun.bullets.splice(i, 1);
				return;
			}
			bullet.update();
		});
	}
	
	fire(...args) {
		this.gun.fire(...args);
	}
}

class Tank {
	constructor() {
		this.body = new TankBody();
		this.turret = new TankTurret();
	}
	
	draw() {
		push();
		
		stroke(255);
		noFill();
		
		push();
		
		translate(this.body.pos.x, this.body.pos.y);
		rotate(this.body.angle);
		
		this.body.draw();
		
		rotate(this.turret.angle);
		
		this.turret.draw();
		
		pop();
		
		this.turret.drawBullets();
		
		pop();
	}
	
	move(...args) {
		this.body.move(...args);
	}
	
	rotate(...args) {
		this.body.rotate(...args);
	}
	
	fire() {
		let pos = createVector(0, 0).add(this.body.pos);
		let turretGunOffset = createVector(0, this.turret.size.l / 3)
				.add(0, this.turret.gun.size.l)
				.rotate(this.body.angle + this.turret.angle);
		pos.add(turretGunOffset);
		this.turret.fire(pos, this.body.angle + this.turret.angle);
	}
}
  </script>
 </body>
</html>
