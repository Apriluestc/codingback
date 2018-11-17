<!doctype html>
<html lang="en">
 <head>
  <meta charset="UTF-8">
  <meta name="Generator" content="EditPlus®">
  <meta name="Author" content="">
  <meta name="Keywords" content="">
  <meta name="Description" content="">
  <title>index</title>
  <style>
	*{margin:0;padding:0;}
	body{background:#434343;overflow:hidden}
	.balloon{
		position:absolute;
		left:0;
		top:0;
		margin:auto;
		width:160px;
		height:160px;
		border-radius:160px 160px 64px 160px;/*圆角: 左上 右上 右下 左下*/
		transform:rotate(45deg);  /*css3旋转 顺时针旋转45度*/
		background:#faf9f9;
		box-shadow:-8px -8px 80px -8px pink inset,48px 48px 24px rgba(220,150,150,0.2);  /*x轴的位置 y轴的位置 影子扩散程度 模糊度 颜色*/
	}
	.balloon:after{
		content:''; /*伪元素的内容*/
		display:block;
		position:absolute;
		bottom:0px;   /*因为气球是旋转的 现在的正下方其实是右下角*/
		right:0px;
		width:0px;
		height:0px;
		border:8px solid #dbbdbd;
		border-top-color:transparent;
		border-bottom-color:transparent;
		border-left-color:transparent;
		transform:rotate(45deg);
		border-radius:16px;
	}
	#wrap{
		width:200px;
		height:200px;
		background:red;
	}
  </style>
 </head>
 <body>
	
	<script>
	   
		
		var num = 10; // 声明遍历num 为div的数量
		//var oBody = document.querySelector('body');  //h5 api 获取元素的方法
		var oBody=document.documentElement || document.body; //body获取兼容性写法
		
		var wW=window.innerWidth;  //获取浏览器窗口的宽度
		var wH=window.innerHeight; //获取浏览器窗口高度
		var timer=null;            //初始化定时器变量
		init(num);
		function init(num){
			for(var i=0;i<num;i++){  //for循环 循环加工厂
				var randomL=Math.random()*wW;        // 随机left范围
					randomL=Math.min(wW-160,randomL); //规范left位置
				var balloon = document.createElement('div'); //用js生成标签
				balloon.className='balloon'; //给创建的div元素设置类名
				balloon.style.left=randomL+'px'; //改变元素的样式中的left的值
				balloon.style.top=wH+'px';
				balloon.speed=Math.random()*5+1;  //自定义属性 创建元素的时候添加
				oBody.appendChild(balloon); //body中添加 元素对象
			}
		}
		timer=setInterval(function(){
			var oBall=document.querySelectorAll('.balloon');//获取页面所有的气球
			for(var i=0,len=oBall.length;i<len;i++){
				oBall[i].style.top = oBall[i].offsetTop-oBall[i].speed+'px';
				oBall[i].onclick=function(){ //谁 触发了什么 谁做了什么事情
					crash(this,function(xxx){
						clearInterval(xxx.timer); //清除动画定时器
						xxx.parentNode.removeChild(xxx);
					});
					//this.parentNode.removeChild(this);	
					init(1);
				}
			}
		},30);
	
		function crash(ele,cb){   //被点击之后撒气效果
			ele.timeouter=setTimeout(function(){
					cb&&cb(ele);
			},500)
			ele.timer=setInterval(function(){
				ele.speed++;  //加速度自增
				ele.style.top=ele.offsetTop-ele.speed+'px'; //加速逃离
				ele.style.width=ele.offsetWidth-10+'px';  //宽度减少
				ele.style.height=ele.offsetHeight-10+'px';  //高度减少
			},30)
		}
		
		
	</script>
 </body>
</html>
	
<!-- 
	JavaScript 基于原型的动态解释性脚本语言 / 脚本语言:
													{
														改变页面上的元素css样式
														相应用户的动作
														处理数据以及数据交互
														json ajax
														
														}	
	js中数数是从0开始不是从1开始

	JavaScript最新元素获取方式 
	
	节点对象自定义属性   !!!
	
	函数的封装与穿参

	鼠标事件

	作用域于let
	
	随机数和定时器运用

	回调函数与简单的闭包  call

	一 画一个气球
			css3
	二 用JavaScript动态生成div
		1.确定生成几个
		2.怎么样用Js创建div
		3.如何随机改变div的left值
			random随机数 0-1之间 包括0 不包括1
		4.如何获取浏览器宽度
	三 如何让气球动起来

		定时器 的应用 setInterval() 改变元素的 top值

		如何获取元素当前top值

		自定义属性


	四  戳气球
		
		鼠标点击事件

		this 如何用js移除一个元素

	
	五  气球的动画
		
		回调函数的应用 

			函数 
			
			作用域
			
			参数
	
		/*
			写一个函数 输出参数中的整数和 以及 1-100的累加和
		*/
	 function myFn(){
			var argSum=0;
			for(var i=0,len=arguments;i<len;i++){
				if(isInt(arguments[i])){
					argSum+=arguments[i];
				}
			}
			function isInt(num){
				return (String(num).indexOf('.') == -1) 
			}
			return {
				'argSum':argSum,
				'sum':(1+100)*(100/2)
			}
		 }
		 console.log(myFn(3.3,2,3,5,1.2,43.2,5,21))
	
	六 学习 
		1. 动力和成就感
		2. 没有人帮你
		显性的知识:
			[获取元素,  属性, 方法 ,工具]  innerHTML
		隐性的知识:
			[闭包,对象,this,函数,作用域 ,json, ajax,call,apply,bind,迭代,递归,封装,回调函数,原型,原型链,面向对象,继承,多态]
			[兼容性,内置的bug]
		架构思想:
			[编程思维] 
			处理需求的方法方式,以及把想法转化为生产的手段和形式
			1.良好的代码规范  !!!
			2.良好的锻炼环境  有人喂招
			3.大型项目的锻炼	
			[数据结构和算法]
			决定了你的天花板
			

				
				
-->
	
