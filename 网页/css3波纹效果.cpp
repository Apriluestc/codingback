<!doctype html> <!--声明文档类型为 html html5文档声明向下兼容-->
<html> <!-- 网页结构正式开始编写-->
	<head> <!-- 与浏览器进行通信 告诉别人本网页的基本信息 -->
		<title>css3波纹动效</title> <!-- 设置网页标题-->
		<meta charset='utf-8' /> <!--设置编码格式 统一语言 gb2312 GBK-->
		<!-- 设置网页关键字 利于搜索引擎搜索 seo优化排名-->
		<meta name='keywords' content='web前端,0基础开发,实战,教室'>
		<!-- 设置网页描述信息 利于seo 免费广告词-->
		<meta name='description' content='今天海牙老师在web前端0基础教室,与同学们一起交流css3效果'>
		<style>     /*style 标签 存放我们的css样式 像是我们的衣柜一样*/
			* {	/* 通配符选择器 选择页面所有的标签元素*/
				margin:0; /*清除默认外边距*/
			}
			#wrap{  /* id选择器 #+id名称 {} */
				width:300px;
				height:300px;
				margin:50px auto 0px; /*外边距 上 左右 下*/
				overflow:hidden; /*超出部分隐藏,只显示可视区域*/
				border:1px solid red; /*边框 宽度 类型 颜色 */
				position:relative; /*设置参考系 相对定位*/
			}
			#wrap .wave{ /*class 选择器 .+ 类名*/
				position:absolute; /*绝对定位*/
				top:0;			/*距离爸爸上方的距离 y轴坐标*/
				left:50%;			/*距离爸爸左边的距离 x轴坐标*/
				z-index:0;         /*定位元素的层级*/
				margin-top:-250px;  /*利用margin把自己往上拉*/
				margin-left:-250px; /*利用margin把自己左右居中*/
				width:500px; /*设置宽度 500px 属性名称:数值+单位 ;*/
				height:500px; /*设置高度 500px*/
				background:#0af; /*设置背景颜色*/
				border-radius:42%; /*设置圆角 100%=500px */
				-webkit-transform:rotate(0deg); /*谷歌浏览器兼容*/
				transform:rotate(0deg); /*设置旋转 rotate(100deg)*/
				transform-origin:50% 48%; /*设置旋转中心 x轴心 y轴心*/
				/*css3动画:动画名称 动画周期 一直循环 运动模式匀速*/
				animation:waves 3s infinite linear;
				opacity:.8;
				
			}
			#wrap .wave.two{
				opacity:.4; /*设置透明度 0-1*/
				animation:waves 1.5s infinite linear;
			}
			#wrap .wave.three{
				background:yellow; 
				opacity:.1; /*设置透明度 0-1*/
				animation:waves 5s infinite linear;
			}
			.title{
					position:absolute;
					width:140px;
					height:20px;
					left:0;
					right:0;
					margin:auto;
					font-size:30px;
					color:#fff;
					z-index:10;
				}
			@keyframes waves{
				0%{  /*动画进度为0的时候,初始值*/
					transform:rotate(0deg); 
				}
				100%{ /*动画结束的时候属性值*/
					transform:rotate(360deg);
				}
				
			}
		</style>
	</head>
	<body>  <!--网页主体展示部分 给用户看的-->
			<!--div标签 盒子模型 通过设置id名称来区分-->
			<!-- id 具有唯一性 身份证号-->
			<!-- 通过css样式修饰我们的div标签 -->
			<!-- class 命名一类人 所有的class名称相同的标签都会受到同样的css影响-->
		<div id='wrap'>
			<div class='wave one'></div>
			<div class='wave two'></div>
			<div class='wave three'></div>
			<div class='title'>这是文字</div>
		</div>
	</body>
</html>

<!-- html+css 学习的重点在哪里?
				兼容性学习 布局思维
				那些标签需要深入学习
					div p span i ul li 
					理解标签的作用
						知道标签的应用范围
						了解标签的兼容性问题 
						了解标签的布局定位
				大概了解一下的标签
					font noscript br
				工作中用不上的标签