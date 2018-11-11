<!doctype html>
<html lang="en">
 <head>
  <meta charset="UTF-8">
  <meta name="Generator" content="EditPlus®">
  <meta name="Author" content="">
  <meta name="Keywords" content="">
  <meta name="Description" content="">
  <style type="text/css">
	html, body{
    width: 100%;
    height: 100%;
    margin: 0;
    padding: 0;
    overflow: hidden;
    background-color: #101010;
}
.container{
    position: absolute;
    width: 500px;
    height: 500px;
    top: 50%;
    left: 50%;
    margin-top: -250px;
    margin-left: -250px;
}
  </style>
  <title>Document</title>
 </head>
 <body>
<div id="jsi-solo-play-container" class="container"></div>
  <script src="https://code.jquery.com/jquery-3.2.1.min.js"></script>
  <div id="jsi-particle-container" class="container"></div>
  <script type="text/javascript">
	var RENDERER = {
	STAR_COUNT : 100,
	TRANSITION_COUNT : 1000,
	
	init : function(){
		this.setParameters();
		this.createElements();
		this.reconstructMethod();
		this.render();
	},
	setParameters : function(){
		this.$container = $('#jsi-solo-play-container');
		this.width = this.$container.width();
		this.height = this.$container.height();
		this.canvas = $('<canvas />').attr({width : this.width, height : this.height}).appendTo(this.$container).get(0);
		this.context = this.canvas.getContext('2d');
		this.stars = [];
		this.status = 1;
		this.count = 0;
		this.theta = 0;
		this.phi = 0;
		this.psi = 0;
	},
	createElements : function(){
		this.wallManager = WALL_MANAGER.init(this.width, this.height, this);
		this.seal = SEAL.init(this.width, this.height, this.wallManager.GONDOLA_LENGTH, this);
		
		for(var i = 0, length = this.STAR_COUNT; i < length; i++){
			this.stars.push(new STAR(this.width, this.height, this.context, this));
		}
	},
	getRandomValue : function(range){
		return range.min + (range.max - range.min) * Math.random();
	},
	reconstructMethod : function(){
		this.render = this.render.bind(this);
	},
	controlStatus : function(){
		switch(this.status){
		case 1:
			if(this.seal.x >= this.wallManager.GONDOLA_LENGTH * 2 + this.seal.RADIUS * 2){
				this.status = 2;
			}
			break;
		case 2:
			this.wallManager.downGondola();
			this.status = 3;
			break;
		case 3:
			if(this.seal.x <= this.wallManager.GONDOLA_LENGTH && this.seal.y >= this.height - this.seal.RADIUS * 2){
				this.status = 4;
			}
			break;
		case 4:
			this.seal.ax = 0;
			this.wallManager.upGondola();
			this.wallManager.changeAngle();
			this.status = 0;
		}
	},
	initStatus : function(){
		this.seal.setInitialVelocity();
		this.status = 1;
	},
	controlView : function(){
		var fadeCount = this.TRANSITION_COUNT / 4;
		
		this.theta += Math.PI / this.TRANSITION_COUNT;
		this.theta %= Math.PI * 4;
		this.count++;
		
		if(this.count >= this.TRANSITION_COUNT && this.count <= this.TRANSITION_COUNT * 3){
			this.phi += Math.PI / this.TRANSITION_COUNT;
			this.phi %= Math.PI * 2;
		}else if(this.count == this.TRANSITION_COUNT * 4){
			this.count = 0;
		}
		if(this.count >= this.TRANSITION_COUNT * 5 / 2 - fadeCount){
			this.psi -= Math.PI / fadeCount;
			
			if(this.psi < 0){
				this.psi = 0;
			}
		}else if(this.count >= this.TRANSITION_COUNT * 3 / 2){
			this.psi += Math.PI / fadeCount;
			
			if(this.psi > Math.PI / 2){
				this.psi = Math.PI / 2;
			}
		}
	},
	render : function(){
		requestAnimationFrame(this.render);
		
		var context = this.context,
			gradient = context.createLinearGradient(0, 0, 0, this.height),
			hue = Math.cos(this.theta),
			luminance = Math.cos(this.phi);
			
		gradient.addColorStop(0, 'hsl(' + (230 - 30 * hue | 0) + ', 100%, ' + (35 + 15 * luminance | 0) + '%)');
		gradient.addColorStop(1, 'hsl(' + (280 - 80 * hue | 0) + ', 100%, ' + (50 + 30 * luminance | 0) + '%)');
		
		context.fillStyle = gradient;
		context.fillRect(0, 0, this.width, this.height);
		
		if(this.count >= this.TRANSITION_COUNT * 3 / 2 && this.count <= this.TRANSITION_COUNT * 5 / 2){
			context.save();
			context.globalAlpha = Math.sin(this.psi);
			
			for(var i = 0, length = this.stars.length; i < length; i++){
				this.stars[i].render(context);
			}
			context.restore();
		}
		context.save();
		this.wallManager.checkCollision(this.seal);
		this.controlStatus();
		this.wallManager.render(context);
		this.seal.render(context);
		context.restore();
		this.controlView();
	}
};
var WALL_MANAGER = {
	LEFT_ANGLE : {min : 0, max : Math.PI / 4},
	RIGHT_ANGLE : {min : -Math.PI * 5 / 4, max : -Math.PI},
	OBSTACLE_LENGTH : 115,
	OBSTACLE_DELTA_LENGTH : 20,
	GONDOLA_LENGTH : 70,
	FLOOR_OFFSET : 80,
	GONDOLA_DELTA_THETA : Math.PI / 30,
	GONDOLA_DELTA_DISTANCE : 5,
	
	init : function(width, height, controller){
		this.width = width;
		this.height = height;
		this.controller = controller;
		this.setParameters(width, height);
		this.contructWalls();
		return this;
	},
	setParameters : function(){
		this.walls = [];
		this.obstacles = [];
		this.doorStatus = 0;
		this.floorStatus = 0;
	},
	contructWalls : function(){
		this.door = new WALL(this.width, this.height, this.GONDOLA_LENGTH, this.FLOOR_OFFSET, this.GONDOLA_LENGTH, this.controller);
		this.floor = new WALL(this.width, this.height, 0, this.FLOOR_OFFSET, this.GONDOLA_LENGTH, this.controller);
		this.walls.push(this.floor);
		this.walls.push(this.door);
		
		for(var i = 0; i < 2; i++){
			this.walls.push(new WALL(this.width, this.height, this.GONDOLA_LENGTH * 2, this.FLOOR_OFFSET * (i * 2 + 1), this.OBSTACLE_LENGTH + this.OBSTACLE_DELTA_LENGTH * i, this.controller, this.LEFT_ANGLE));
			this.walls.push(new WALL(this.width, this.height, this.width, this.FLOOR_OFFSET * (i * 2 + 2), this.OBSTACLE_LENGTH + this.OBSTACLE_DELTA_LENGTH * i, this.controller, this.RIGHT_ANGLE));
		}
		for(var i = 2, length = this.walls.length; i < length; i++){
			this.obstacles.push(this.walls[i]);
		}
	},
	checkCollision : function(seal){
		for(var i = 0, length = this.walls.length; i < length; i++){
			var boundary = this.walls[i].getBoundary();
			
			if((seal.x < boundary.x - seal.RADIUS || seal.x > boundary.x + boundary.width + seal.RADIUS)
				|| seal.y < boundary.y - seal.RADIUS || seal.y > boundary.y + boundary.height + seal.RADIUS){
				continue;
			}
			var sin = Math.sin(boundary.angle),
				cos = Math.cos(boundary.angle),
				x = seal.x - boundary.x0,
				y = seal.y - boundary.y0,
				x1 = x * cos + y * sin,
				y1 = -x * sin + y * cos;
				
			if(Math.abs(y1) > seal.RADIUS){
				return;
			}
			var vx1 = seal.vx * cos + seal.vy * sin,
				vy1 = -seal.vx * sin + seal.vy * cos;
				
			if(y1 < 0 && vy1 > 0 || y1 > 0 && vy1 < 0){
				y1 = -seal.RADIUS * vy1 / Math.abs(vy1);
				vy1 *= -seal.RESTITUTION;
				seal.judgeToSwoon(vy1);
			}else if(y1 > 0 && vy1 < 0 || y1 < 0 && vy1 > 0){
				vx1 *= -seal.RESTITUTION;
				seal.judgeToSwoon(vx1);
			}
			seal.x = boundary.x0 + x1 * cos - y1 * sin;
			seal.y = boundary.y0 + x1 * sin + y1 * cos;
			seal.vx = vx1 * cos - vy1 * sin;
			seal.vy = vx1 * sin + vy1 * cos;
		}
	},
	downGondola : function(){
		this.doorStatus = 1;
	},
	upGondola : function(){
		this.doorStatus = 3;
	},
	controlStatus : function(){
		this.controlDoorStatus();
		this.controlFloorStatus();
	},
	controlDoorStatus : function(){
		switch(this.doorStatus){
		case 1:
			this.door.angle -= this.GONDOLA_DELTA_THETA;
			
			if(this.door.angle <= -Math.PI / 2){
				this.door.angle = -Math.PI / 2;
				this.doorStatus = 0;
				this.floorStatus = 1;
			}
			break;
		case 2:
			this.door.angle += this.GONDOLA_DELTA_THETA;
			
			if(this.door.angle >= 0){
				this.door.angle = 0;
				this.doorStatus = 0;
				this.floorStatus = 0;
			}
			break;
		case 3:
			this.door.angle -= this.GONDOLA_DELTA_THETA;
			
			if(this.door.angle <= -Math.PI / 2){
				this.door.angle = -Math.PI / 2;
				this.doorStatus = 0;
				this.floorStatus = 2;
			}
			break;
		case 4:
			this.door.angle += this.GONDOLA_DELTA_THETA;
			
			if(this.door.angle >= 0){
				this.door.angle = 0;
				this.doorStatus = 0;
				this.floorStatus = 0;
				this.controller.initStatus();
			}
		}
	},
	controlFloorStatus : function(){
		switch(this.floorStatus){
		case 1:
			this.door.y += this.GONDOLA_DELTA_DISTANCE;
			this.floor.y += this.GONDOLA_DELTA_DISTANCE;
			
			if(this.floor.y >= this.height){
				this.door.y = this.height;
				this.floor.y = this.height;
				this.doorStatus = 2;
				this.floorStatus = 0;
			}
			break;
		case 2:
			this.door.y -= this.GONDOLA_DELTA_DISTANCE;
			this.floor.y -= this.GONDOLA_DELTA_DISTANCE;
			
			if(this.floor.y <= this.FLOOR_OFFSET){
				this.door.y = this.FLOOR_OFFSET;
				this.floor.y = this.FLOOR_OFFSET;
				this.doorStatus = 4;
				this.floorStatus = 0;
			}
		}
	},
	changeAngle : function(){
		for(var i = 0, length = this.obstacles.length; i < length; i++){
			this.obstacles[i].changeAngle();
		}
	},
	render : function(context){
		for(var i = 0, length = this.walls.length; i < length; i++){
			this.walls[i].render(context);
		}
		this.controlStatus();
	}
};
var WALL = function(width, height, x, y, length, controller, range){
	this.width = width;
	this.height = height;
	this.x = x;
	this.y = y;
	this.length = length;
	this.controller = controller;
	this.range = range;
	this.angle = range ? this.controller.getRandomValue(range) : 0;
	this.init();
};
WALL.prototype = {
	CHANGE_COUNT : 10,
	HEIGHT : 5,
	
	init : function(){
		this.deltaAngle = 0;
		this.changeCount = 0;
	},
	getBoundary : function(){
		var sin = Math.sin(this.angle),
			cos = Math.cos(this.angle);
			
		return {
			x0 : this.x,
			y0 : this.y,
			x : Math.min(this.x, this.x + this.length * cos),
			y : Math.min(this.y, this.y + this.length * sin),
			width : Math.abs(this.length * cos),
			height : Math.abs(this.length * sin),
			angle : this.angle
		};
	},
	changeAngle : function(){
		if(this.range){
			this.deltaAngle = (this.controller.getRandomValue(this.range) - this.angle) / this.CHANGE_COUNT;
			this.changeCount = this.CHANGE_COUNT;
		}
	},
	render : function(context){
		context.save();
		context.translate(this.x, this.y);
		context.rotate(this.angle);
		
		var gradient = context.createLinearGradient(0, 0, this.length, 0);
		gradient.addColorStop(0, 'hsl(20, 60%, 50%)');
		gradient.addColorStop(0.5, 'hsl(20, 60%, 60%)');
		gradient.addColorStop(1, 'hsl(20, 60%, 50%)');
		context.strokeStyle = gradient;
		context.lineWidth = this.HEIGHT;
		context.beginPath();
		context.moveTo(0, 0);
		context.lineTo(this.length, 0);
		context.stroke();
		
		context.fillStyle = 'hsl(20, 40%, 40%)';
		context.beginPath();
		context.arc(0, 0, 5, 0, Math.PI * 2, false);
		context.fill();
		context.restore();
		
		if(this.changeCount > 0){
			this.changeCount--;
			this.angle += this.deltaAngle;
		}
	}
};
var SEAL = {
	RADIUS : 30,
	GRAVITY : 0.3,
	RESTITUTION : 0.7,
	LAUGH_COUNT : 50,
	LAUGH_COUNTDOWN : {min : 100, max : 200},
	INITIAL_VELOCITY : {min : 3, max : 8},
	SWOON_COUNT : 20,
	VELOCITY_THRESHOLD : 5,
	SACTION : -0.01,
	
	init : function(width, height, top, controller){
		this.width = width;
		this.height = height;
		this.top = top;
		this.controller = controller;
		this.setParameters();
		return this;
	},
	setParameters : function(){
		this.x = this.RADIUS;
		this.y = this.top - this.RADIUS;
		this.setInitialVelocity();
		this.laughing = false;
		this.laughCountDown = this.controller.getRandomValue(this.LAUGH_COUNTDOWN) | 0;
		this.laughCount = this.LAUGH_COUNT;
		this.swoonCount = 0;
		this.theta = 0;
	},
	setInitialVelocity : function(){
		this.vx = this.controller.getRandomValue(this.INITIAL_VELOCITY);
		this.vy = 0;
		this.ax = 0;
	},
	render : function(context){
		context.save();
		context.translate(this.x, this.y);
		context.scale(this.RADIUS / 80, this.RADIUS / 80);
		context.rotate(this.theta);
		context.fillStyle = '#00FF00';
		context.beginPath();
		this.drawContour(context);
		this.drawEye(context, -1);
		this.drawEye(context, 1);
		this.drawMouth(context);
		this.drawBeard(context, -1);
		this.drawBeard(context, 1);
		this.drawNose(context);
		context.fill();
		context.restore();
		
		if(this.x <= this.RADIUS){
			this.x = this.RADIUS;
			this.vx *= -this.RESTITUTION;
			this.judgeToSwoon(this.vx);
		}else if(this.x >= this.width - this.RADIUS){
			this.x = this.width - this.RADIUS;
			this.vx *= -this.RESTITUTION;
			this.judgeToSwoon(this.vx);
		}
		if(this.y <= this.RADIUS){
			this.y = this.RADIUS;
			this.vy *= -this.RESTITUTION;
			this.judgeToSwoon(this.vy);
		}else if(this.y >= this.height - this.RADIUS){
			this.y = this.height - this.RADIUS;
			this.vy *= -this.RESTITUTION;
			this.judgeToSwoon(this.vy);
			this.ax = this.SACTION;
		}
		if(this.swoonCount > 0){
			this.swoonCount--;
		}
		this.vx += this.ax;
		this.vy += this.GRAVITY;
		this.x += this.vx;
		this.y += this.vy;
		this.theta += Math.PI * this.vx / 300;
	},
	judgeToSwoon : function(velocity){
		if(Math.abs(velocity) > this.VELOCITY_THRESHOLD){
			this.swoonCount = this.SWOON_COUNT;
		}
	},
	drawContour : function(context){
		context.beginPath();
		context.fillStyle = '#FFFFFF';
		context.arc(0, 0, 80, 0, Math.PI * 2, false);
		context.fill();
		context.beginPath();
		context.fillStyle = '#DDDDDD';
		context.arc(0, 0, 50, 0, Math.PI * 2, false);
		context.fill();
	},
	drawEye : function(context, offset){
		if(this.swoonCount == 0){
			var gradient = context.createRadialGradient(20 * offset, -8, 0, 20 * offset, -8, 30);
			gradient.addColorStop(0, '#FFFFFF');
			gradient.addColorStop(0.2, '#000000');
			gradient.addColorStop(1, '#000000');
			context.beginPath();
			context.fillStyle = gradient;
			context.strokeStyle = '#000000';
			context.lineWidth = 3;
			context.moveTo(30 * offset, 5);
			context.bezierCurveTo(35 * offset, -13, 15 * offset, -20, 10 * offset, -3);
			context.bezierCurveTo(15 * offset, 5, 30 * offset, 10, 30 * offset, 5);
			context.fill();
			context.stroke();
		}else{
			context.strokeStyle = '#000000';
			context.lineWidth = 2;
			context.beginPath();
			
			for(var i = 0; i < 3; i++){
				context.moveTo(5 * offset, -10);
				context.lineTo(30 * offset, -10 * i);
			}
			context.stroke();
		}
	},
	drawMouth : function(context){
		context.save();
		context.beginPath();
		context.translate(0, 35);
		context.scale(1, 0.6);
		context.fillStyle = '#000000';
		context.arc(0, 0, 20, 0, Math.PI * 2, false);
		context.fill();
		context.restore();
	},
	drawBeard : function(context, offset){
		context.beginPath();
		context.fillStyle = '#CCCCCC';
		context.strokeStyle = '#BBBBBB';
		
		var rate = (this.LAUGH_COUNT - this.laughCount) / this.LAUGH_COUNT;
		
		if(rate == 1 && this.laughing){
			this.laughCountDown = this.controller.getRandomValue(this.LAUGH_COUNTDOWN) | 0;
			this.laughing = false;
		}
		context.moveTo(0, 15 + 5 * rate);
		context.lineTo(0, 40 - 10 * rate);
		context.bezierCurveTo(40 * offset, 55 - 5 * rate, 40 * offset, 5 - 25 * rate, 0 * offset, 15 - 10 * rate);
		context.fill();
		context.stroke();
		
		for(var i = 0; i < 5; i++){
			context.beginPath();
			context.lineWidth = 2;
			context.moveTo(20 * offset, 20 + i * 4 - 10 * rate);
			context.bezierCurveTo((40 - i * 3) * offset, 25 + i * 5 - 15 * rate, (50 - i * 3) * offset, 30 + i * 6 - 20 * rate, (60 - i * 3) * offset, 35 + i * 7 - 25 * rate);
			context.stroke();
		}
		if(this.laughCountDown >= 0){
			if(this.laughCountDown-- <= 0){
				this.laughing = true;
				this.laughCount = this.LAUGH_COUNT;
			}
		}
		if(this.laughing && this.laughCount >= 0){
			this.laughCount--;
		}
		if(!this.laughing && this.laughCount <= this.LAUGH_COUNT){
			this.laughCount++;
		}
	},
	drawNose : function(context){
		context.beginPath();
		context.fillStyle = '#000000';
		context.strokeStyle = '#000000';
		context.lineWidth = 5;
		context.moveTo(-8, 15);
		context.lineTo(8, 15);
		context.lineTo(0, 25);
		context.closePath();
		context.fill();
		context.stroke();
	}
};
var STAR = function(width, height, context, renderer){
	this.width = width;
	this.height = height;
	this.context = context;
	this.renderer = renderer;
	this.init();
};
STAR.prototype = {
	RADIUS_RANGE : {min : 1, max : 4},
	
	init : function(){
		this.x = this.renderer.getRandomValue({min : 0, max : this.width});
		this.y = this.renderer.getRandomValue({min : 0, max : this.height});
		this.radius = this.renderer.getRandomValue(this.RADIUS_RANGE);
		
		this.gradient = this.context.createRadialGradient(0, 0, 0, 0, 0, this.radius);
		this.gradient.addColorStop(0, 'hsla(220, 80%, 100%, 1)');
		this.gradient.addColorStop(0.1, 'hsla(220, 80%, 80%, 1)');
		this.gradient.addColorStop(0.25, 'hsla(220, 80%, 50%, 1)');
		this.gradient.addColorStop(1, 'hsla(220, 80%, 30%, 0)');
	},
	render : function(){
		var context = this.context;
		
		context.save();
		context.translate(this.width / 2, this.height / 2);
		context.translate(this.x - this.width / 2, this.y - this.height / 2);
		context.beginPath();
		context.fillStyle = this.gradient;
		context.arc(0, 0, this.radius, 0, Math.PI * 2, false);
		context.fill();
		context.restore();
	}
};
$(function(){
	RENDERER.init();
});
  </script>
 </body>
</html>
