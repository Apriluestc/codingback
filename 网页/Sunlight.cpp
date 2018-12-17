<!DOCTYPE html>
<html>
 <head>
	<!--声明当前页面的编码集：charset=gbk,gb2312(中文编码)，utf-8国际编码-->
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <!--当前页面的三要素-->
    <title>css3动画</title>
		
    <meta name="author" content="P+老师" />

    <!--css,js-->
    <style type="text/css">
		*{margin:0;padding:0;}
		html,body{
			height:100%;
		}
		body{
			background:radial-gradient(ellipse at center,#34679a 0%, #214163 50%, #0d1926 100%);/*径向渐变   椭圆*/
		}
		body > div{
			width:200px;/*宽度 px像素  cm*/
			height:200px;/*高度*/
			border:1px #fff solid;/*边框 宽度 风格 颜色*/
			border-radius:50%;/*圆角*/
			position:absolute;
			top:15%;
			left:50%;
			margin-left:-101px;
			transform:rotateX(80deg) rotateY(20deg);
			transform-style:preserve-3d;
		}
		body > div:nth-of-type(2){
			transform:rotateX(-80deg) rotateY(20deg);
		}
		body > div:nth-of-type(3){
			transform:rotateX(-70deg) rotateY(60deg);
		}
		body > div:nth-of-type(4){
			transform:rotateX(70deg) rotateY(60deg);
		}
		body > div:first-of-type:after{
			width:40px;
			height:40px;
			content:"";
			background:#fff;
			position:absolute;
			top:50%;
			left:50%;
			margin-top:-20px;
			margin-left:-20px;
			transform:rotateX(80deg);
			border-radius:50%;
			animation:nucleus 2s infinite linear;
		}
		body > div > div{
			width:200px;
			height:200px;
			position:relative;
			transform-style:preserve-3d;
			animation:trail 1s infinite linear; /*自定义动画  动画名称 时间 播放次数 速度*/
		}
		body > div > div:after{
			content:"";
			width:5px;
			height:5px;
			background:#fff;
			position:absolute;
			top:-5px;
			left:50%;
			margin-left:-5px;
			border-radius:50%;
			box-shadow:0 0 12px #fff;/*阴影 x y 模糊度 颜色*/
			animation:particle 1s infinite linear;
		}
		/*自定义动画执行*/
		@keyframes trail{
			from{
				transform:rotateZ(0deg);
			}
			to{
				transform:rotateZ(360deg);
			}
		}
		@keyframes particle{
			from{
				transform:rotateX(90deg) rotateY(0deg);
			}
			to{
				transform:rotateX(90deg) rotateY(-360deg);
			}
		}
		@keyframes nucleus{
			0%{
				box-shadow:0 0 0 transparent;
			}
			50%{
				box-shadow:0 0 25px #fff;
			}
			100%{
				box-shadow:0 0 0 transparent;
			}
		}
		body > div:nth-of-type(2) > div,
		body > div:nth-of-type(2) > div:after{
			animation-delay:-0.5s;
		}
		body > div:nth-of-type(3) > div,
		body > div:nth-of-type(3) > div:after{
			animation-delay:-1s;
		}
		body > div:nth-of-type(4) > div,
		body > div:nth-of-type(4) > div:after{
			animation-delay:-1.5s;
		}

   </style>
 </head>
 <body>
	<div><div></div></div>
	<div><div></div></div>
	<div><div></div></div>
	<div><div></div></div>
 </body>
</html>