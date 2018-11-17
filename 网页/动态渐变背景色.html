<!doctype html>
<html lang="en">
 <head>
  <meta charset="UTF-8">
  <meta name="Generator" content="EditPlus®">
  <meta name="Author" content="">
  <meta name="Keywords" content="">
  <meta name="Description" content="">
  <title>Document</title>
  <style>
	*{margin:0;padding:0;}
	body#wrap{width:100%;height:500px;
}
  </style>
 </head>
 <body id="wrap">
	
	<script>

		/* RGB 色盘变化
				1.rgb颜色的变化只有 ++ -- ；
				2.什么时候发生改变
				3.阈值和变化规律：
				{
					 if(R==255&&G==0){B++;}
					 if(B==255&&G==0){R--;}
					 if(B==255&&R==0){G++;}
					 if(R==0&&G==255){B--;}
					 if(G==255&&B==0){R++;}
					 if(R==255&&B==0){G--;}
				}
				4.数据分析归类
				{	 
					 if(G==255&&B==0){R++;}
					 if(B==255&&R==0){G++;}
					 if(R==255&&G==0){B++;}
					 
					 if(G==0&&B==255){R--;}
					 if(B==0&&R==255){G--;}
					 if(R==0&&G==255){B--;}	
				}
				5.解决方案转化成代码
				{
					R , G , B
					var color=[R,G,B]
	`				color[0]  //R
					利用数组操作原本应该是3个变量的值

					++ , --
				}
		*/
	
		(function(){
			var oWrap=document.getElementById('wrap');
			var max=220;  /*存储封值*/
			var min=180;	  /*存储谷值*/
			var color=[max,min,min]; /*根据初始值红色来初始化数组*/
			var timer=null;
			var length=color.length;
			var colorL,colorR
			timer=setInterval(change,20);
			/*不容许在机组运行中直接修改代码*/
			function change(){
				/*在定时器中每过20毫秒 执行一次代码*/
				/*检测一次数组*/
				for(var i=0;i<length;i++){
					i%=length;
				   var arrX=(i+1)%length;
				   var arrY=(i+2)%length;
					if(color[i]==max&&color[arrX]==min){
						color[arrY]++;
					}
					if(color[i]== min&&color[arrX]==max){
						color[arrY]--;
					}
				 colorL='#'+convert(color[0])+''+convert(color[1])+''+convert(color[2])+'';
				colorR='#'+convert(color[2])+''+convert(color[0])+''+convert(color[1])+'';
						
					}
					gColor(colorL,colorR);
				}
			
			function convert(sRgb){ /*rgb转换成HEX*/
				var sRgb=sRgb;
				var sHex=sRgb.toString(16);
				sHex=sHex.length<2?'0'+sHex:sHex 
				/* 三目判断  判断条件 ？ 符合条件 ：不符合条件*/
				return sHex;
			}
			function gColor(colorL,colorR){
				if(navigator.userAgent.match(/Trident/i)&&navigator.userAgent.match(/MSIE [7|8|9].0/i)){
					//通过正则检测浏览器信息是否是ie 并且 ie版本是不是 7或者8或者9 之一
					oWrap.style.filter = "progid:DXImageTransform.Microsoft.gradient( startColorstr=" + colorL + ", endColorstr=" + colorR + ",GradientType=0 )";
				}else{
					oWrap.style.background='-webkit-linear-gradient(left,'+colorL+','+colorR+')' //谷歌
					oWrap.style.background='-ms-linear-gradient(left,'+colorL+','+colorR+')'  //ie 10 11
				}
			 
			
			}
		})();
			
	</script>
 </body>
</html>
