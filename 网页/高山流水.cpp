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
  margin: 0;
  padding: 0;
  overflow: hidden;
}
  </style>
  <title>Document</title>
 </head>
 <body>
<canvas id="canvas"></canvas>
  <script src="https://code.jquery.com/jquery-3.2.1.min.js"></script>
  <div id="jsi-particle-container" class="container"></div>
  <script type="text/javascript">
	var canvas = document.getElementById('canvas'),
    c = canvas.getContext("2d"),
    particles = {},
    particleIndex = 0,
    particleNum = 50,
    gravity = 0.7;

// full screen
canvas.width = window.innerWidth;
canvas.height = window.innerHeight;

// particle
function Particle(){
  
  this.posX = canvas.width / 2; // position X
  this.posY = canvas.height / 8; // position Y
  this.vx = Math.random() * 10 - 5; // velocity X
  this.vy = Math.random() * 10 - 5 ; // velocity Y
  this.width = 1; // particle width
  this.height = Math.random() * 6 - 3; // particle height
  
  particleIndex++;
  particles[particleIndex] = this;
  this.id = particleIndex;
  
  this.life= 0;
  this.death = 140;
  
  //random color
  this.colors = [
    "rgba(100, 100, 100,"+ (Math.random() + .5) +")",
    "rgba(52, 152, 200,"+ (Math.random() + .5) +")",
    "rgba(41, 128, 250,"+ (Math.random() + .5) +")"];
  this.color = this.colors[Math.floor(Math.random() * 3)];
}

// draw
Particle.prototype.draw = function(){
  this.posX += this.vx;
  this.posY += this.vy;
  
  this.life++;

  if(this.life >= this.death){
    delete particles[this.id];
  }
  
  if(this.posY > (canvas.height - 5)){
    this.vx *= 0.8;
    this.vy *= -0.5;
    this.posY = (canvas.height - 5);
  }
  
  this.vy += gravity;
  
  c.fillStyle = this.color;
  c.fillRect(this.posX,this.posY, this.width, this.height);
}

setInterval(function(){ 
  c.fillStyle = "rgba(0,0,0,0.4)";
  c.fillRect(0,0,canvas.width,canvas.height);
  
  for(var i = 0; i < particleNum; i++){
    new Particle();
  }
  
  for(var i in particles){
    particles[i].draw();
  }
}, 30);
  </script>
 </body>
</html>
