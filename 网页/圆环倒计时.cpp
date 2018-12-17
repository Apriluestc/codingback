<!doctype html>
<html lang="en">
 <head>
  <meta charset="UTF-8">
  <meta name="Generator" content="EditPlus®">
  <meta name="Author" content="">
  <meta name="Keywords" content="">
  <meta name="Description" content="">
  <title>countDown</title>
  <style>
	*{margin:0;padding:0; box-sizing:border-box;}
	.wrap{
	  display:flex; /*开启弹性盒模型*/
	  flex-direction:column; /*声明主轴方向纵向 row*/
	  justify-content:space-between; /*主轴方向对齐方式: 两端对齐*/
	  align-items:center; /*辅轴 横向 对齐方式 :居中*/
	  width:400px;
	  height:600px;
	  margin:50px auto; 
	  box-shadow:0 0 8px #222; /*盒子阴影 横向位移 纵向位移 影子大小与羽化程度  颜色*/
	  background:#e1e1e1;
	}

	.wrap .clock{
		display:flex;
		justify-content:center;
		align-items:center;
		width:100%;
		height:280px;
		background:#368; /*海牙蓝*/
	}

	.wrap .clock .c_box{
		position:relative;
		display:flex;
		flex-direction:row;
		justify-content:space-around;
		align-items:center;
		width:200px;
		height:200px;
		background:#fff;
		
		
	}
	
	.clock .c_box .c_left{
		overflow:hidden;
		width:100px;
		height:200px;
		background:#368;
	}

	.clock .c_box .c_right{
		position:relative;
		width:100px;
		height:200px;
		background:#368;
	}

	.borderA{
		border:5px solid transparent; 
	}
	.clock .c_box .c_left .l_rotate{
		width:200px;
		height:200px;
		border-radius:50%; /*圆角*/
		border-left:5px solid #fff;
		border-bottom:5px solid #fff;
		transform:rotate(45deg);
		
	}
	
	.clock .c_box .c_right .r_rotate{
		position:absolute;
		right:0;
		width:200px;
		height:200px;
		border-radius:50%; /*圆角*/
		border-right:5px solid #fff;
		border-bottom:5px solid #fff;
		transform:rotate(-45deg); /*逆时针旋转45度*/
		
	}
	
	.wrap .txt{
		position:absolute;
		color:#fff;
		font-size:30px;
		text-shadow:0 0 5px #000;
	}
	.wrap .control{
		display:flex;
		flex-direction:column;
		justify-content:space-around;
		align-items:center;
		width:100%;
		height:300px;
		
	}
	
	.wrap .control #set_time{
		outline:none; /*聚焦框样式*/
		width:120px;
		height:25px;
		padding:10px;
		border:none;
		border-radius:10px;
		
	}
	.wrap .control .start{
		width:100px;
		height:100px;
		background:#368;
		border-radius:50%;
		color:#fff;
		font-size:20px;
		text-align:center;
		line-height:100px;
		cursor:pointer;
	}
  </style>
 </head>
 <body>
	<div class='wrap'>
		<div class='clock'>
			<div class='c_box'>
				<div class='c_left'>
					<div class='l_rotate borderA'></div>
				</div>
				<div class='c_right'>
					<div class='r_rotate borderA'></div>
				</div>
				<div class='txt'>
					00:00
				</div>
			</div>
		</div>
		<div class='control'>
			<input id='set_time'  type='number' placeholder='请输入分钟' />
			<div class='start'>开始</div>
		</div>
	</div>
	<script>	
			//javascript 基于原型的动态解释性脚本语言 ( 编译性语言)
			/*
				1.响应用户操作 事件触发 
				2.操作DOM BOM 样式等 
				3.数据交互 ajax json 正则表达式 
				4.框架 插件 node vue angular
			*/
			/*
				用户设置时间
				点击开始按钮
				获取用户输入的分钟 
				操作txt实时改变
				操作左右半圆的rotate 的值 完成效果

				start按钮  setTime 输入框  txt内容  l_rotate,r_rotate

				倒计时时间


				1.点击开始获取用户输入的时间
				2.转化时间类型以及转化为毫秒
					1分钟 = 多少毫秒
					1*60*1000 60000毫秒
				3.业务逻辑处理 判断 规范
				3.倒计时时间算法 
					setInterval 
					requestAnimationFrame 帧动画 cpu 14 16
					setTimeout 延时定时器 递归替代setInterval

						

			*/
			var oStart = document.querySelector('.start'); //获取开始按钮
			var oSetTime= document.querySelector('#set_time');//获取输入框
			var oTxt = document.querySelector('.txt');//获取时间文本
			var oLrotate=document.querySelector('.l_rotate'); //获取左半圆
			var oLrotate=document.querySelector('.r_rotate'); //获取右半圆
			var count={
				time:0,
				toggle:true, 
				lRt:45,
				rRt:-45,
				timeOuter:null,
				mm:0,
				ss:0,
			}; //json 对象
		
			// 谁 触发了什么事件 谁做了什么事情

			oStart.onclick=function(){
				if(count.toggle&&oSetTime.value>0){
					count.time = parseInt(oSetTime.value)*60*1000; //获取输入框的设置时间
					oSetTime.style.display='none';//操作css样式
					oStart.innerHTML='停止';
					oSetTime.value='';
					timeOut(timeRun); //  点击开始之后倒计时
				}else if(!count.toggle){
					oSetTime.style.display='block';//操作css样式
					oStart.innerHTML='开始';
				}else{
					alert('请设置时间');
				}
				count.toggle=!count.toggle; //布尔值取反操作	
			}

			function timeRun(){
				if(count.time<=0){
					rezero(); //重置停止
					return; //终止函数向下执行
				}
				count.time -=1000;
				count.mm= parseInt(count.time/1000/60); //毫秒取分钟
				count.ss= parseInt(count.time/1000%60);
				oTxt.innerHTML=count.mm+':'+count.ss;
			}
			
			function rezero(){ //归零重置函数
				clearTimeout(count.timeOuter)
				count.time=0;
				oText.innerHTML='00:00';
				oSetTime.style.display='block';//操作css样式
				oStart.innerHTML='开始';

			}
			function timeOut(cb){
				cb&&cb();  //如果cb存在那就运行它 短路运算符
				count.timeOuter=setTimeout(function(){
					timeOut(cb);
				},1000);
			}
		
			
			
			//我输入一个值 函数 你返回一个结果
			//
			function module(){ //纯函数 函数副作用
				var num=0; //私有变量
				return {
						set:function(newNum){  //设置
							num = newNum;
						},
						get:function(){  //获取
							return num;
					}
				}
				
			}
			//module().set(10); //函数执行之后 内部属性 回收
			
			var newModule = module(); //newModule 是什么类型 对象
			newModule.set(100);
			
			console.log(newModule.get());
			
			newModule.set(1000);
			console.log(newModule.get());
			//模块和函数  私有性
		
	</script>
 </body>
</html>
<!--
	1.querySelector h5 api dom选择器  $选择器用法 一样
	 querySelectorAll  
	getElementById();
	getElementsByClassName();
	getElementsByTagName();

	copper 码农
		终止 copper
		经验 定时器 if 对象与变量
		鲁棒
	javaScript 
			初级阶段[方法,事件,对象,数组,字符串等包装对象函数,关键词,工具,变量,控制流程]
			进阶部分[词法作用域,对象,函数声明,变量声明,函数表达式,js引擎解析,递归,回调函数,迭代,闭包,面向对象,封装,继承,多态,高级函数,模块化,碰撞检测等模块思想,运动插件,ajax,json,正则表达式,数组高级应用,包装对象,原型,原型链,作用域链,引用类型,原始数据类型,模块化,垃圾GC,this与指针,事件监听,原型开发]
			高阶部分[编程思维]
	健壮性 可扩展性 低耦合性 适应性 可维护性
-->