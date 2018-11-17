

<!DOCTYPE html>
<html>

<head>
<meta charset="utf-8" />
<title>智能机器人</title>
 <meta name="Keywords" content="">
 <meta name="Description" content="">
<link rel="stylesheet" type="text/css" href="css/tulin.css"/>
<script src="js/jquery-1.11.1.min.js" type="text/javascript" charset="utf-8"></script>

</head>
<style type="text/css">
	* {
		margin: 0;
		padding: 0;
	}
	
	body {
		font-size: 12px;
		font-family: "微软雅黑";
		background: url(img/bg.jpg) no-repeat;
		width: 100%;
		height: 100vh;
		background-size: cover;
	}
	
	#top {
		width: 100%;
		height: 60px;
		background: rgba(15, 25, 50, 0.3);
		color: #fff;
		line-height: 60px;
		text-align: center;
		font-size: 30px;
	}
	/* end public */
	
	#box {
		width: 800px;
		height: 600px;
		background: rgba(255, 255, 255, .5);
		margin: 100px auto 0;
	}
	/* head start */
	
	.b-head {
		width: 100%;
		height: 60px;
		background-color: #4CAF50;
	}
	
	.h-img {
		margin: 0 20px;
		float: left;
		user-select: none;
	}
	
	.h_span {
		color: #fff;
		font-size: 18px;
		line-height: 60px;
		float: left;
		user-select: none;
		cursor: default;
	}
	/* end head */
	/* body start */
	
	.b-body {
		width: 100%;
		height: 420px;
		overflow: auto;
		margin: 20px 0;
	}
	
	.rotWord,.mWord{
		width: 100%;
		margin-top: 10px;
		overflow: hidden;
	}
	
	.rotWord span {
		background: url(img/rot.png);
		height: 40px;
		width: 40px;
		margin-left: 20px;
		float: left;
	}
	
	.rotWord p {
		word-break: break-all;
		top: 4px;
		float: left;
		color: #fff;
		font-size: 14px;
		margin-left: 10px;
		padding: 10px;
		line-height: 24px;
		background: rgba(0, 0, 255, .5);
		border-radius: 6px;
		max-width: 220px;
	}
	
	.mWord span {
		background: url(img/my.png);
		height: 40px;
		width: 40px;
		float: right;
		margin-right: 20px;
	}
	
	.mWord p {
		word-break: break-all;
		/*自动换行*/
		top: 2px;
		float: right;
		color: #fff;
		font-size: 14px;
		margin-right: 10px;
		padding: 10px;
		line-height: 24px;
		background: #19b955;
		border-radius: 6px;
		max-width: 220px;
	}
	/* end body */
	/* footer start */
	
	.b-footer {
		width: 760px;
		height: 60px;
		margin: 0 20px;
		font-size: 16px;
		color: #666;
	}
	
	#f-left {
		padding-left: 20px;
		outline: none;
		overflow: hidden;
		width: 620px;
		height: 60px;
		float: left;
		background: rgba(0, 0, 0, .1);
		font-size: 18px;
		border: none;
		border-radius: 5px;
	}
	
	#btn {
		width: 100px;
		height: 60px;
		background: #666666;
		float: right;
		cursor: pointer;
		text-align: center;
		line-height: 60px;
		font-size: 18px;
		color: #fff;
		user-select: none;
		border-radius: 10px;
	}
</style>
<body>
	<div id="top">Java开发人工智能机器人</div>
	<div id="box">
	<!-- head start -->
		<div class="b-head">
			<img  class="h-img" alt="" src="img/logo.png" width=80; height=60;/>
			<span class="h_span">人工智能机器人</span>
		</div>
	<!-- end head -->
	
	<!-- body start -->
		<div class="b-body">
			<div class="rotWord">
				<span></span>
				<p>
					嗨，最近想我没有？
				</p>
			</div>
			
		</div>
		<!-- end body -->
		
		<!-- footer start -->
		<div class="b-footer">
				<input type="text" name="text" id="f-left" />
				<div id="btn">发送</div>
		</div>
		<!-- end footer -->
	</div>
	<script type="text/javascript">
		var text = $("#f-left");
		text.focus();
		function action() {
			if(text.val()==null||text.val()==""){
				text.focus();
				return;
			}
			$(".b-body").append("<div class='mWord'><span></span><p>" + text.val() + "</p></div>");
			$(".b-body").scrollTop(10000000);
			
			 var args={
			 		type : "get",
					url : "robot",//数据库地址
					data : {"text" : text.val()},
					success : function(data){
						var result = $.parseJSON(data).text;
						$(".b-body").append("<div class='rotWord'><span></span> <p id='member'>" + result + "</p></div>");
						$(".b-body").scrollTop(10000000);
						result = result.replace(/\s+/g, ",");/*如果有空格，用，代替 */
						var url = 'http://tsn.baidu.com/text2audio?lan=zh&cuid=123&ctp=1&tok=24.30b741d50d76454dcb1f6eafa964b411.2592000.1494328483.282335-9389343&tex='+result;/*调用百度语音的接口*/
			    		var obj = $("<audio src="+url+" autoplay></audio>");
			    		$("body").remove("audio");
			    		$("body").append(obj);
						}
			}
			
			ajax(args);
			//初始化
			text.val("");
			text.focus();
			
		};
		$("#btn").click(function(){//鼠标点击
			action();
		});
		$(document).keydown(function(event){//回车
			if(event.keyCode==13){
				action();
			}
		});
		
		
		
		
		
		function ajax(mJson){//封装ajax
		
			var type=mJson.type||'get';
			var url=mJson.url;
			var data=mJson.data;
			var success=mJson.success;
			var error=mJson.error;
			var dataStr='';
			if(data){
				for (var key in data){
					dataStr+=key+'='+data[key]+'&';
				}
				dataStr+=new Date().getTime();
				if(type.toLowerCase()=='get'){
					url+='?'+dataStr;
				}
			}
			
			
			var xhr=new XMLHttpRequest();
			xhr.open(type,url,true);
			xhr.setRequestHeader('content-type' , 'application/x-www-form-urlencoded');
			xhr.send(null);
			xhr.onreadystatechange=function(){
				if(xhr.readyState==4){
					if(xhr.status>=200&&xhr.status<300){
						success&&success(xhr.responseText);
					}else
					{
						error&&error(xhr.status);
					}
				}
			}
		}
 
		
				
	</script>
</body>

</html>