<!doctype html>
<html lang="en">
 <head>
  <meta charset="UTF-8">
  <meta name="Generator" content="EditPlus®">
  <meta name="Author" content="">
  <meta name="Keywords" content="">
  <meta name="Description" content="">
  <title>潜水SVG动画</title>
  <style>
body{
  background-color:#10ABFD;
  width:100%;
  height:100%;
  overflow:hidden;
}
svg{
  position:absolute;
   width:80%;
  top:20%;
 left:10%;
  visibility:hidden;
}
#container{
  position:absolute;
  width:100%;
  height:100%;
  text-align:center;
  margin-left:auto;
  margin-right:auto;
}
  </style>
 </head>
 <body>
	
<div id="container">

<svg class="arches-svg-node" version="1.1"
	 xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" xmlns:a="http://ns.adobe.com/AdobeSVGViewerExtensions/3.0/" 
	 viewBox="0 0 552.7 62.1">

<path class="arches" fill="none" stroke="#ecf0f1" stroke-width="10" stroke-linecap="round" stroke-linejoin="round" stroke-miterlimit="10" d="
	M505,55c0-27.6-22.4-50-50-50s-50,22.4-50,50c0-27.6-22.4-50-50-50s-50,22.4-50,50c0-27.6-22.4-50-50-50s-50,22.4-50,50
	c0-27.6-22.4-50-50-50s-50,22.4-50,50c0-27.6-22.4-50-50-50S5,27.4,5,55"/>
 
<path class="splash-lines" fill="none" stroke="#ecf0f1" stroke-width="6" stroke-linecap="round" stroke-linejoin="round" d="
	M549.7,46.6l-21.8,12.6 M531.9,25.8l-12.6,21.8 M504.2,18.3v25.1 M476.4,25.8L489,47.6 M458.7,46.6l21.8,12.6"/>
</svg>
</div>
  <style>
var container = document.getElementById("container");
var arches = document.getElementsByClassName("arches");
var archesSVGNode = document.querySelector(".arches-svg-node");
var splashLines = document.getElementsByClassName("splash-lines");
TweenMax.set(splashLines, {
  drawSVG: "40 60"
});

TweenMax.set("svg", {
  visibility: "visible"
});

//console.log(splashLines.getTotalLength())
var cloned = archesSVGNode.cloneNode(true);
container.appendChild(cloned);

TweenMax.set(cloned, {
  transformOrigin: "50% 100%",
  rotationX: 180,
  y: "+=57",
  alpha: 0.08
});

TweenMax.set(container, {
  position: "absolute",
  left: "50%",
  xPercent: -50,
  top: "50%",
  yPercent: -50
});
TweenMax.set(arches, {
  drawSVG: "100% 100%"
});

var tl = new TimelineMax({ repeat: -1, yoyo: false, repeatDelay: 1 });
tl.timeScale(1);

tl
  .to(arches, 0.8, {
    drawSVG: "550 600",
    ease: Linear.easeNone
  })
  .to(arches, 2, {
    drawSVG: "-1% -5%",
    ease: Linear.easeNone
  })
  .to(
    splashLines,
    0.8,
    {
      drawSVG: 0,
      ease: Power2.easeOut,
      alpha: 1
    },
    "-=0.2"
  )
  .to(
    splashLines,
    0.8,
    {
      alpha: 0
    },
    "-=0.65"
  );

  </style>
 </body>
</html>
