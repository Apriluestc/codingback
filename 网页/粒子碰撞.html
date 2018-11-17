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
  margin:0px; 
  padding: 0px; 
  background: #000;
  overflow: hidden;
  
}

canvas { 
  background:#000
}
  </style>
  <title>Document</title>
 </head>
 <body>
<canvas id="world">
  <p class="noCanvas">You need a <a href="https://www.google.com/chrome">modern browser</a> to view this.</p></canvas>
  <script src="https://code.jquery.com/jquery-3.2.1.min.js"></script>
  <div id="jsi-particle-container" class="container"></div>
  <script type="text/javascript">
	/**
 * Heavily inspired by Hakim's (@hakimel( 
 * experiments with canvas!
 */

// http://paulirish.com/2011/requestanimationframe-for-smart-animating/
// http://my.opera.com/emoller/blog/2011/12/20/requestanimationframe-for-smart-er-animating
 
// requestAnimationFrame polyfill by Erik Möller. fixes from Paul Irish and Tino Zijdel
 
// MIT license
 
(function() {
  var lastTime = 0;
  var vendors = ['ms', 'moz', 'webkit', 'o'];
  for(var x = 0; x < vendors.length && !window.requestAnimationFrame; ++x) {
    window.requestAnimationFrame = window[vendors[x]+'RequestAnimationFrame'];
    window.cancelAnimationFrame = window[vendors[x]+'CancelAnimationFrame'] || window[vendors[x]+'CancelRequestAnimationFrame'];
  }
 
  if (!window.requestAnimationFrame)
    window.requestAnimationFrame = function(callback, element) {
      var currTime = new Date().getTime();
      var timeToCall = Math.max(0, 16 - (currTime - lastTime));
      var id = window.setTimeout(function() { callback(currTime + timeToCall); }, timeToCall);
      lastTime = currTime + timeToCall;
      return id;
    };
 
    if (!window.cancelAnimationFrame)
      window.cancelAnimationFrame = function(id) {
        clearTimeout(id);
      };
}());

(function() {
  var SCREEN_WIDTH = 900;
  var SCREEN_HEIGHT = 500;

  var RADIUS = 110;

  var RADIUS_SCALE = 1;
  var RADIUS_SCALE_MIN = 1;
  var RADIUS_SCALE_MAX = 1.5;

  var QUANTITY = 100;

  var canvas;
  var context;
  var particles;

  var mouseX = (window.innerWidth - SCREEN_WIDTH);
  var mouseY = (window.innerHeight - SCREEN_HEIGHT);

  var targetX = 0;
  var targetY = 0;

  var PARTICLE_SIZE = 10;

  function init(){

    canvas = document.getElementById('world');

    if(canvas && canvas.getContext) {
      context = canvas.getContext('2d');
      context.globalCompositeOperation = 'destination-over';
      window.addEventListener('resize', windowResizeHandler, false);
      windowResizeHandler();
      createParticles();
      loop();
    }
  }
  
  function createParticles(){
  
    particles = [];
    var depth = 0;

    for (var i = 0; i < QUANTITY; i++) {
      var posX = PARTICLE_SIZE/2 + Math.random() * (window.innerWidth - PARTICLE_SIZE/2)
      var posY = PARTICLE_SIZE/2 + Math.random() * (window.innerHeight - PARTICLE_SIZE/2);

      var speed = 2;
      var directionX = -speed + (Math.random() * speed*2);
      var directionY = -speed + (Math.random()* speed*2);

      var particle = {
        position: { x: posX, y: posY },
        size: PARTICLE_SIZE,
        directionX: directionX,
        directionY: directionY,
        speed: speed,
        targetX: posX,
        targetY: posY,
        depth: depth,
        index:i,
        fillColor: '#' + (Math.random() * 0x00eaff + 0xff0000 | 0).toString(16)
      };

      particles.push( particle );
    }
  }

  function loop(){

    context.fillStyle = 'rgba(0,0,0,0.2)';
    context.fillRect(0, 0, context.canvas.width, context.canvas.height);

    var z = 0;
    var xdist = 0;
    var ydist = 0;
    var dist = 0;

    for (var i=0; i < particles.length; i++){

      var particle = particles[i];

      var lp = { x: particle.position.x, y: particle.position.y };

      if(particle.position.x <=particle.size/2 || particle.position.x >= SCREEN_WIDTH - PARTICLE_SIZE/2){
        particle.directionX *= -1;
      }

      if(particle.position.y <=particle.size/2 || particle.position.y >= SCREEN_HEIGHT - PARTICLE_SIZE/2){
        particle.directionY *= -1;
      }

      for(var s=0; s < particles.length; s++) {
        var bounceParticle = particles[s];
          if(bounceParticle.index != particle.index) {
            //what are the distances
            z = PARTICLE_SIZE;
            xdist = Math.abs(bounceParticle.position.x - particle.position.x);
            ydist = Math.abs(bounceParticle.position.y - particle.position.y);
            dist = Math.sqrt(Math.pow(xdist, 2) + Math.pow(ydist, 2));
            if(dist < z) {
              randomiseDirection(particle);
              randomiseDirection(bounceParticle);
            }
          }
        }

        particle.position.x -= particle.directionX;
        particle.position.y -= particle.directionY;

        context.beginPath();
        context.fillStyle = particle.fillColor;
        context.lineWidth = particle.size;
        context.moveTo(lp.x, lp.y);
        context.arc(particle.position.x, particle.position.y, particle.size/2, 0, Math.PI*2, true);
        context.closePath();
        context.fill();
    }
    
    requestAnimationFrame(loop);
  }

  function randomiseDirection (particle) {

    //pick a random deg
    var d = 0;
    while((d == 0) || (d == 90) || (d == 180) || (d == 360)) {
      d = Math.floor(Math.random() * 360);
    }

    var r = (d * 180)/Math.PI;
    particle.directionX = Math.sin(r) * particle.speed;
    particle.directionY = Math.cos(r) * particle.speed;

  }

  function windowResizeHandler() {
    SCREEN_WIDTH = window.innerWidth;
    SCREEN_HEIGHT = window.innerHeight;
    canvas.width = SCREEN_WIDTH;
    canvas.height = SCREEN_HEIGHT;
  }

  init();

}())
  </script>
 </body>
</html>
