<!doctype html>
<html lang="en">
 <head>
  <meta charset="UTF-8">
  <meta name="Generator" content="EditPlus®">
  <meta name="Author" content="">
  <meta name="Keywords" content="">
  <meta name="Description" content="">
  <title>泡沫</title>
  <style>
body{
  background-color:#000;
  overflow:hidden;
}
body, html {
    height: 100%;
    width: 100%;
    margin: 0;
    padding: 0;
}

.labSVG{
  
  width:100%;
  height:100%;
  max-height:600px;
}
.flask{
  stroke:#f7f7f7;
}
.liquidBack{
  fill:#0248AD;
}
/*
.liquidFront, .liquidBubblesGroup{
  fill:#005DE9;
}
*/
.pop{
  stroke:#005DE9;
}

.darkBubbleGroup{
  fill:#171717;
}
  </style>
 </head>
 <body>

<svg class="labSVG" xmlns="http://www.w3.org/2000/svg"	viewBox="0 0 600 600"	>
<defs>
<linearGradient id="frontGrad" gradientUnits="userSpaceOnUse" x1="300" y1="100" x2="300" y2="600">
	<stop  offset="0.5" style="stop-color:#005DE9"/>
	<stop  offset="0.8" style="stop-color:#ED1E79"/>
</linearGradient>  
  <mask id="liquidMask">
<path class="liquidMask" fill="#FFFFFF" d="M337,273.9V129h-74v144.8c-37,14.7-63.1,50.8-63.1,93c0,55.2,44.8,100,100,100
		s100-44.8,100-100C400,324.7,373.9,288.6,337,273.9z"/>  
  </mask>
  <clipPath id="sphereMask">
  <circle fill="red" stroke="none" stroke-width="0.4957" stroke-miterlimit="10" cx="300" cy="367" r="100"/>    
  </clipPath>
  <filter id="goo" color-interpolation-filters="sRGB">
      <feGaussianBlur in="SourceGraphic" stdDeviation="7 7" result="blur" />
      <feColorMatrix in="blur" mode="matrix" values="1 0 0 0 0  0 1 0 0 0  0 0 1 0 0  0 0 0 19 -7" result="cm" />
    
        <feComposite in="SourceGraphic" in2="cm" />
  	</filter>
</defs>
<g class="liquidMaskGroup" clip-path="url(#sphereMask)">
  <path class="liquidBack" fill="none" d="M1199.9,365.1c-41.8,0-79.4,9.8-107.4,8.1c-38.9-2.3-54.5-16.4-83.6-19.9
	c-29.1-3.5-71.5,3.4-110.4,1c-28-1.7-56.4-13.7-98.2-13.7c-41.8,0-70.2,12-98.2,13.7c-38.9,2.3-81.4-4.6-110.4-1
	c-29.1,3.5-44.7,17.5-83.6,19.9c-28,1.7-65.7-8.2-107.5-8.2c-41.8,0-79.5,9.9-107.5,8.2c-38.9-2.3-54.5-16.3-83.6-19.9
	c-29.1-3.5-72,3.4-110.9,1c-28-1.7-56.7-13.7-98.7-13.7V438h1200L1199.9,365.1z"/>
  <g class="liquidBubblesGroup" fill="url(#frontGrad)" clip-path="url(#sphereMask)">
    <path class="liquidFront" fill="url(#frontGrad)"  d="M1199.9,329.6c-44,0-70.6,29.4-96.4,33c-36.1,5.1-70.7-14.5-106.8-9.4	c-25.8,3.7-52.4,33.3-96.4,33.3c-44,0-70.7-29.7-96.4-33.4c-36.1-5.1-70.7,14.4-106.8,9.2c-25.8-3.7-52.4-33.3-96.5-33.3	c-44,0-70.7,29.7-96.5,33.3c-36.1,5.1-70.7-14.4-106.8-9.3c-25.8,3.7-52.4,33.3-96.5,33.3c-44,0-70.7-29.7-96.5-33.3	c-36.1-5.1-71.2,14.4-107.3,9.3c-25.8-3.7-52-33.3-97-33.3V533h1200L1199.9,329.6z"/>
      <circle class="bubble0" cx="350" cy="400" r="8"/>
      <circle class="bubble1" cx="320" cy="400" r="6"/> 
      <circle class="bubble2" cx="300" cy="400" r="12"/>
      <circle class="bubble3" cx="276" cy="400" r="3"/>     
      <circle class="bubble4" cx="244" cy="400" r="4"/>  
      <circle class="bubblePop0" cx="280" cy="400" r="5"/>  
      <circle class="bubblePop1" cx="310" cy="390" r="5"/>        
      <circle class="bubblePop2" cx="350" cy="410" r="5"/>        
    </g>
  <g class="darkBubbleGroup" fill="none" stroke="none"> 
    <circle class="darkBubble" cx="310" cy="480" r="7"/>
    <circle class="darkBubble" cx="360" cy="480" r="5"/> 
    <circle class="darkBubble" cx="230" cy="480" r="6"/>  
    <circle class="darkBubble" cx="345" cy="480" r="3"/> 
    <circle class="darkBubble" cx="290" cy="480" r="8"/>  
    <circle class="darkBubble" cx="320" cy="480" r="2"/>      
    <circle class="darkBubble" cx="260" cy="480" r="9"/> 
  </g>
  <path class="pop" fill="none" stroke="none" stroke-width="4" stroke-linecap="round" stroke-linejoin="round" stroke-miterlimit="10" d="
    M37.4,9c2.1-2.1,4.2-4.2,6.3-6.3 M2,44.4c2.2-2.2,4.5-4.5,6.7-6.7 M37.4,37.4c2.1,2.1,4.2,4.2,6.3,6.3 M2,2c2.2,2.2,4.5,4.5,6.7,6.7
    "/>  
  </g>
  
		<!--path class="flask" opacity="1" fill="none" stroke="none" stroke-width="10" stroke-linecap="round" stroke-linejoin="round" stroke-miterlimit="10" d="		M379.2,108.2l-20.5,20.5l0.1,126.3h0.2c39.7,21,66.7,62.9,66.7,111c0,69.4-56.3,125.7-125.7,125.7S174.3,435.4,174.3,366
		c0-48.1,27.1-89.9,66.8-111l0.1-126.3l-20.5-20.5"/-->  
<radialGradient id="shine" cx="280" cy="337" r="100" gradientUnits="userSpaceOnUse">

	<stop offset="0.02"  style="stop-color:#fff;stop-opacity:0.2"/>

	<stop  offset="1" style="stop-color:#1B52D4;stop-opacity:0.1"/>
</radialGradient>

  <circle opacity="0.9" fill="url(#shine)" stroke="none" stroke-width="0.4957" stroke-miterlimit="10" cx="300" cy="367" r="100"/>

</svg>

	<script>
var select = function(s) {
      return document.querySelector(s);
    }, liquidFront = select('.liquidFront'), liquidMaskGroup = select('.liquidMaskGroup'), liquidBack = select('.liquidBack'), bubble0 = select('.bubble0'), bubble1 = select('.bubble1'), bubble2 = select('.bubble2'), bubble3 = select('.bubble3'), bubble4 = select('.bubble4'), pop = select('.pop'), bubblePop0 = select('.bubblePop0'), bubblePop1 = select('.bubblePop1'), bubblePop2 = select('.bubblePop2'), liquidBubblesGroup = select('.liquidBubblesGroup'), darkBubble = document.getElementsByClassName('darkBubble');
var xLink = "http://www.w3.org/1999/xlink";
var pop1 = pop.cloneNode(true);
var pop2 = pop.cloneNode(true);
liquidMaskGroup.appendChild(pop1);
liquidMaskGroup.appendChild(pop2);

var isDevice = (/android|webos|iphone|ipad|ipod|blackberry/i.test(navigator.userAgent.toLowerCase()));

if(!isDevice){
  
  TweenMax.set(liquidBubblesGroup, {
    filter:'url(#goo)',
    '-webkit-filter':'url(#goo)'
  })
}




var mainTimeline = new TimelineMax();

var frontLiquidTimeline = new TimelineMax({repeat:-1});
frontLiquidTimeline.to(liquidFront, 3, {
  x:-600,
  ease:Linear.easeNone
})

var backLiquidTimeline = new TimelineMax({repeat:-1});
backLiquidTimeline.from(liquidBack, 3, {
  x:-800,
  ease:Linear.easeNone
})

var b0 = new TimelineMax({repeat:-1, delay:0, repeatDelay:2, onRepeat:doRepeat, onRepeatParams:[bubble0]});
b0.timeScale(1)
b0.to(bubble0, 0.8, {
  attr:{
    cy:'-=80'
  },
  ease:Sine.easeOut
} )

.to(bubble0, 0.8, {
  attr:{
    cy:'+=80'
  },
  ease:Sine.easeIn
})


var b1 = new TimelineMax({repeat:-1, delay:3, repeatDelay:5, onRepeat:doRepeat, onRepeatParams:[bubble1]});
b1.timeScale(1)
b1.to(bubble1, 0.7, {
  attr:{
    cy:'-=120'
  },
  ease:Sine.easeOut
} )

.to(bubble1, 0.7, {
  attr:{
    cy:'+=120'
  },
  ease:Sine.easeIn
})


var b2 = new TimelineMax({repeat:-1, delay:1, repeatDelay:6, onRepeat:doRepeat, onRepeatParams:[bubble2]});
b2.timeScale(1)
b2.to(bubble2, 1, {
  attr:{
    cy:'-=70'
  },
  ease:Sine.easeOut
} )

.to(bubble2, 1, {
  attr:{
    cy:'+=70'
  },
  ease:Sine.easeIn
})

var b3 = new TimelineMax({repeat:-1, delay:1, repeatDelay:4, onRepeat:doRepeat, onRepeatParams:[bubble3]});
b3.timeScale(1)
b3.to(bubble3, 0.72, {
  attr:{
    cy:'-=140'
  },
  ease:Sine.easeOut
} )

.to(bubble3, 0.72, {
  attr:{
    cy:'+=140'
  },
  ease:Sine.easeIn
})
.to(bubble3, 0.88, {
  attr:{
    cy:'-=110'
  },
  ease:Sine.easeOut
} )

.to(bubble3, 0.88, {
  attr:{
    cy:'+=110'
  },
  ease:Sine.easeIn
})



var b4 = new TimelineMax({repeat:-1, delay:2, repeatDelay:2, onRepeat:doRepeat, onRepeatParams:[bubble4]});
b4.timeScale(1)
b4.to(bubble4, 0.7, {
  attr:{
    cy:'-=99'
  },
  ease:Sine.easeOut
} )

.to(bubble4, 0.7, {
  attr:{
    cy:'+=99'
  },
  ease:Sine.easeIn
})

//with pops

var bPop0 = new TimelineMax({repeat:-1, delay:2, repeatDelay:5});
bPop0.timeScale(1)
bPop0.to(bubblePop0, 0.82, {
  attr:{
    cy:'-=110'
  },
  ease:Sine.easeOut
} )
.set(bubblePop0, {
  alpha:0
})
.set(pop, {
  x:256,
  y:269,
  transformOrigin:'50% 50%'
})

.from(pop, 0.2,{
  scale:0,
  transformOrigin:'50% 50%'
})
.to(pop, 0.1,{
  alpha:0
},'-=0.1')


var bPop1 = new TimelineMax({repeat:-1, delay:1, repeatDelay:7});
bPop1.timeScale(1)
bPop1.to(bubblePop1, 0.92, {
  attr:{
    cy:'-=130'
  },
  ease:Sine.easeOut
} )
.set(bubblePop1, {
  alpha:0
})
.set(pop1, {
  x:306,
  y:262,
  transformOrigin:'50% 50%'
})

.fromTo(pop1, 0.2,{
  scale:0
},{
  scale:0.8,
  transformOrigin:'50% 50%'
})
.to(pop1, 0.1,{
  alpha:0
},'-=0.1')


var bPop2 = new TimelineMax({repeat:-1, delay:5, repeatDelay:9});
bPop2.timeScale(1)
bPop2.to(bubblePop2, 0.92, {
  attr:{
    cy:'-=90'
  },
  ease:Sine.easeOut
} )
.set(bubblePop2, {
  alpha:0
})
.set(pop2, {
  x:346,
  y:322,
  transformOrigin:'50% 50%'
})

.fromTo(pop2, 0.2,{
  scale:0
},{
  scale:0.8,
  transformOrigin:'50% 50%'
})
.to(pop2, 0.1,{
  alpha:0
},'-=0.1')


var darkBubble0 = new TimelineMax({repeat:-1});
darkBubble0.staggerTo(darkBubble, 2, {
  attr:{
    cy:370,
    r:0
  },
  fill:'#2E69E2',
  ease:Power3.easeIn
}, 0.9);


mainTimeline.add(frontLiquidTimeline, 0)
.add(backLiquidTimeline, 0)
.add(b0, 0)
.add(b1, 0)
.add(b2, 0)
.add(b3, 0)
.add(b4, 0)
.add(bPop0, 0)
.add(bPop1, 0)
.add(bPop2, 0)
.add(darkBubble0, 0);


mainTimeline.timeScale(1)



function doRepeat(bubble){
  
  TweenMax.set(bubble, {
    attr:{
      cx:getBetweenVal(240, 360)
    }
  })
  
}

TweenMax.set('svg',{
  transformOrigin:'50% 50%',
  //:180,
  scale:1.2
})


function getBetweenVal(min,max)
{
    return Math.floor(Math.random()*(max-min+1)+min);
}
	</script>
 </body>
</html>
