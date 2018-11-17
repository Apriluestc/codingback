<!doctype html>
<html lang="en">
 <head>
  <meta charset="UTF-8">
  <meta name="Generator" content="EditPlus®">
  <meta name="Author" content="">
  <meta name="Keywords" content="">
  <meta name="Description" content="">
  <style type="text/css">
	html {background: repeating-linear-gradient(
  -15deg,
  #111,
  #222 2px,
  #222 2px,
  #111 4px);
}

canvas {position: absolute;
  width: 600px;
  height: 400px;
  top: 50%;
  left: 50%;
  margin-left: -300px;
  margin-top: -200px;
  box-shadow: 0 0 30px 1px #555;
}

  </style>
  <title>Document</title>
 </head>
 <body>
<!-- Special thanks to Daniel Shiffman's awesome P5* tutorials on Youtube without which, I would not know what P5* is !

See my previous sketch of Simon's Ball with sounds in P5* here: https://codepen.io/brettmitchell/pen/zwPLvv

This uis version 2 - work in progress to be updated - I hope you enjoy and thanks for flying by ^_^
-->
  <script src="https://code.jquery.com/jquery-3.2.1.min.js"></script>
  <div id="jsi-particle-container" class="container"></div>
  <script type="text/javascript">
	var opacity = 255;
var speedY = 10;
var speedX = 5;
var dx = 1;
var diameter = 35;
var dy = 1;
var r = 255;
var g = 255;
var b = 255;
var simonsBall;

function setup() {
  createCanvas(600, 400);
  simonsBall = new Particle(25, 25);
  

}

function draw() {
  background(28, 28, 28);
  simonsBall.update();
  simonsBall.show();
}

function Particle(x, y) {
  this.x = x;
  this.y = y;
  
  this.yspeed = 0;
  this.dy = dy;
  this.dx = dx;
  this.speedY = speedY;
  this.speedX = speedX;
  this.diameter = diameter;  
  this.history = [];
  
  this.update = function() {
    this.y += this.speedY * this.dy;
    this.x += this.speedX * this.dx;
    
    if (this.y > height - diameter / 2) {
      r = 255; g = 255; b = 0;
      this.y = height - diameter / 2;
      this.dy *= -1;
      this.speedY = random(1, 15);
      this.speedX = random(1, 15);

    }
    if (this.y < this.diameter / 2) {
      r = 0; g = 0; b = 255;
      this.y = this.diameter / 2;
      this.dy *= -1;
      this.speedY = random(1, 15);
      this.speedX = random(1, 15);

    }
       if (this.x > width - this.diameter / 2) {
      r = 0; g = 255; b = 0;
      this.x = width - this.diameter / 2;
      this.dx *= -1;
      this.speedY = random(1, 15);
      this.speedX = random(1, 15);

    }
    if (this.x < this.diameter / 2) {
      r = 255; g = 0; b = 0;
      this.x = this.diameter / 2;
      this.dx *= -1;
      this.speedY = random(1, 15);
      this.speedX = random(1, 15);

    }
   
   
    var v = createVector(this.x, this.y);
    this.history.push(v);
    
    if (this.history.length > 50) {
    this.history.splice(0, 1);
    }
  }

  
  this.show = function() {
    noStroke();
    fill(0);
    ellipse(this.x, this.y, this.diameter, this.diameter);
    
    for (var i = 0; i < this.history.length; i++) {
      var pos = this.history[i];
      var o = map(opacity, 0, 50, 0, 255);
      fill(r + i, g + i, b + i, opacity - i);
      var rady = map(i, this.history.length, 0, diameter, 0);
      var offsets = random(-10, 0);

      ellipse(pos.x, pos.y, rady + offsets, rady + offsets);
  }
}
}

  </script>
 </body>
</html>
