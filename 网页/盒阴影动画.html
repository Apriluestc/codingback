<!--文档声明为 html（最新html5）-->
<!doctype html>
<html>
	<head>
		<!--声明当前页面编码格式为国际编码（utf-8）还有一种中文编码（gbk/gb2312）-->
		<meta charset="UTF-8">
		<!--网页三要素-->
		<meta name="Keywords" content="关键词,关键词">
		<meta name="Description" content="描述">
		<title>网页的标题</title>
		<!--css 层叠样式表 衣服，化妆品 修饰body 页面-->
		<style>
		* {
  padding: 0;
  margin: 0;
}

body {
  height: 100%;
  font-size: 16px;
  background-color: black;
}

body::before {
  content: "";
  width: 2px;
  height: 2px;
  border-radius: 50%;
  position: absolute;
  background-color: hsl(90, 100%, 50%);
  -webkit-animation: testAnimacion 5s ease-in-out infinite alternate-reverse;
  animation: testAnimacion 5s ease-in-out infinite alternate-reverse;
}
		</style>
	</head>
	<body>
	<script>
	var s = document.createElement("style");
document.head.appendChild(s);

var cx = window.innerWidth / 2;
var cy = window.innerHeight / 2;
var rad = Math.PI / 180;

var R = 150,
  r = R / 16,
  kx = 5,
  ky = 6,
  phi = Math.PI / 2,
  x,
  y,
  t;

function pointOnLemniscate() {
  (x = (R * Math.cos(t) / (1 + Math.sin(t) * Math.sin(t))).toFixed(
    5
  )), (y = (R *
    Math.sin(t) *
    Math.cos(t) /
    (1 + Math.sin(t) * Math.sin(t))).toFixed(5));
  return (o = {
    x: x,
    y: y
  });
}

function pointOnLissajous() {
  x = (R * Math.sin(kx * t + phi)).toFixed(5);
  y = (R * Math.sin(ky * t)).toFixed(5);
  return (o = {
    x: x,
    y: y
  });
}

function pointOnHeart() {
  x = (16 * r * (Math.sin(t) * Math.sin(t) * Math.sin(t))).toFixed(5);
  y = (-13 * r * Math.cos(t) +
    5 * r * Math.cos(2 * t) +
    2 * r * Math.cos(3 * t) +
    r * Math.cos(4 * t)).toFixed(5);
  return (o = {
    x: x,
    y: y
  });
}

function getShadow(pointOnCurve) {
  var boxShadowRy = [];
  for (var a = 0; a < 360; a += 0.5) {
    t = a * rad;
    var o = pointOnCurve();
    boxShadowRy.push(
      o.x + "px" + " " + o.y + "px" + " 0px 1px hsl(" + a + ",100%,50%)"
    );
  }
  var boxShadowStr = boxShadowRy.join();
  return boxShadowStr;
}

s.textContent = "body::before{";
s.textContent += "left:" + cx + "px;";
s.textContent += "top:" + cy + "px;";
s.textContent += "box-shadow:" + getShadow(pointOnLissajous);
s.textContent += "}";

var vendors = [/*'-ms-', '-moz-',*/ "-webkit-", /*'-o-',*/ ""];
for (var i = 0; i < vendors.length; i++) {
  s.textContent += "@" + vendors[i] + "keyframes testAnimacion {";
  s.textContent +=
    "50% {" +
    vendors[i] +
    "box-shadow:" +
    getShadow(pointOnLemniscate) +
    ";background-color:hsl(90,100%,50%);}";
  s.textContent += "55% {background-color:transparent;}";
  s.textContent +=
    "100% {" +
    vendors[i] +
    "box-shadow:" +
    getShadow(pointOnHeart) +
    ";background-color:transparent;}";
  s.textContent += "}";
}

	</script>
	</body>
</html>
