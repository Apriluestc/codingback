<!--文档声明为 html（最新html5）-->
<!doctype html>
<html>
	<head>
		<!--声明当前页面编码格式为国际编码（utf-8）还有一种中文编码（gbk/gb2312）-->
		<meta charset="UTF-8">
		<!--网页三要素-->
		<meta name="Keywords" content="关键词,关键词">
		<meta name="Description" content="描述">
		<title>旋转闪光球体</title>
		<style>
	body {
  margin: 0;
  display: flex;
  height: 100vh;
  overflow: hidden;
  justify-content: center;
  align-items: center;
  background: black;
}

.mommy {
  width: 500px;
  height: 500px;
  position: relative;
  perspective: 800px;
}

.daddy {
  width: 500px;
  height: 500px;
  transform-style: preserve-3d;
  animation: rotate 25s infinite linear;
}

span {
  display: inline-block;
  position: absolute;
  top: 50%;
  left: 50%;
  perspective: 800px;
  transform-style: preserve-3d;
  width: 0;
  height: 0;
}
span:before {
  content: "";
  width: 4px;
  height: 4px;
  display: inline-block;
  position: absolute;
  top: calc(50% - 2px);
  left: calc(50% - 2px);
  background: currentColor;
  color: inherit;
  border-radius: 50%;
  animation: invertRotate 25s infinite linear, scale 2s infinite linear;
  box-shadow: 0 0 10px currentColor;
}

.mommy span:nth-child(1) {
  transform: translate3d(2.41129px, 1.01948px, 249.98629px);
  color: #ff0500;
}
.mommy span:nth-child(1):before {
  animation-delay: 0s, -0.00667s;
}

.mommy span:nth-child(2) {
  transform: translate3d(3.64768px, 3.75579px, 249.94517px);
  color: #ff0a00;
}
.mommy span:nth-child(2):before {
  animation-delay: 0s, -0.01333s;
}

.mommy span:nth-child(3) {
  transform: translate3d(2.84548px, 7.31901px, 249.87664px);
  color: #ff0f00;
}
.mommy span:nth-child(3):before {
  animation-delay: 0s, -0.02s;
}

.mommy span:nth-child(4) {
  transform: translate3d(-0.30569px, 10.46445px, 249.78071px);
  color: #ff1400;
}
.mommy span:nth-child(4):before {
  animation-delay: 0s, -0.02667s;
}

.mommy span:nth-child(5) {
  transform: translate3d(-5.44486px, 11.89724px, 249.65738px);
  color: #ff1a00;
}
.mommy span:nth-child(5):before {
  animation-delay: 0s, -0.03333s;
}

.mommy span:nth-child(6) {
  transform: translate3d(-11.57533px, 10.60317px, 249.50668px);
  color: #ff1f00;
}
.mommy span:nth-child(6):before {
  animation-delay: 0s, -0.04s;
}

.mommy span:nth-child(7) {
  transform: translate3d(-17.25167px, 6.13348px, 249.32862px);
  color: #ff2400;
}
.mommy span:nth-child(7):before {
  animation-delay: 0s, -0.04667s;
}

.mommy span:nth-child(8) {
  transform: translate3d(-20.88379px, -1.22116px, 249.12321px);
  color: #ff2900;
}
.mommy span:nth-child(8):before {
  animation-delay: 0s, -0.05333s;
}

.mommy span:nth-child(9) {
  transform: translate3d(-21.09811px, -10.41121px, 248.89049px);
  color: #ff2e00;
}
.mommy span:nth-child(9):before {
  animation-delay: 0s, -0.06s;
}

.mommy span:nth-child(10) {
  transform: translate3d(-17.08109px, -19.77685px, 248.63047px);
  color: #ff3300;
}
.mommy span:nth-child(10):before {
  animation-delay: 0s, -0.06667s;
}

.mommy span:nth-child(11) {
  transform: translate3d(-8.83099px, -27.34361px, 248.34319px);
  color: #ff3800;
}
.mommy span:nth-child(11):before {
  animation-delay: 0s, -0.07333s;
}

.mommy span:nth-child(12) {
  transform: translate3d(2.74163px, -31.21313px, 248.02868px);
  color: #ff3d00;
}
.mommy span:nth-child(12):before {
  animation-delay: 0s, -0.08s;
}

.mommy span:nth-child(13) {
  transform: translate3d(15.89625px, -29.97464px, 247.68696px);
  color: #ff4200;
}
.mommy span:nth-child(13):before {
  animation-delay: 0s, -0.08667s;
}

.mommy span:nth-child(14) {
  transform: translate3d(28.32425px, -23.05434px, 247.31808px);
  color: #ff4700;
}
.mommy span:nth-child(14):before {
  animation-delay: 0s, -0.09333s;
}

.mommy span:nth-child(15) {
  transform: translate3d(37.55093px, -10.92755px, 246.92209px);
  color: #ff4d00;
}
.mommy span:nth-child(15):before {
  animation-delay: 0s, -0.1s;
}

.mommy span:nth-child(16) {
  transform: translate3d(41.40805px, 4.85919px, 246.49901px);
  color: #ff5200;
}
.mommy span:nth-child(16):before {
  animation-delay: 0s, -0.10667s;
}

.mommy span:nth-child(17) {
  transform: translate3d(38.48926px, 21.87498px, 246.0489px);
  color: #ff5700;
}
.mommy span:nth-child(17):before {
  animation-delay: 0s, -0.11333s;
}

.mommy span:nth-child(18) {
  transform: translate3d(28.49842px, 37.17963px, 245.57181px);
  color: #ff5c00;
}
.mommy span:nth-child(18):before {
  animation-delay: 0s, -0.12s;
}

.mommy span:nth-child(19) {
  transform: translate3d(12.41584px, 47.82911px, 245.06779px);
  color: #ff6100;
}
.mommy span:nth-child(19):before {
  animation-delay: 0s, -0.12667s;
}

.mommy span:nth-child(20) {
  transform: translate3d(-7.56279px, 51.42479px, 244.5369px);
  color: #ff6600;
}
.mommy span:nth-child(20):before {
  animation-delay: 0s, -0.13333s;
}

.mommy span:nth-child(21) {
  transform: translate3d(-28.31983px, 46.60624px, 243.97919px);
  color: #ff6b00;
}
.mommy span:nth-child(21):before {
  animation-delay: 0s, -0.14s;
}

.mommy span:nth-child(22) {
  transform: translate3d(-46.30345px, 33.39159px, 243.39473px);
  color: #ff7000;
}
.mommy span:nth-child(22):before {
  animation-delay: 0s, -0.14667s;
}

.mommy span:nth-child(23) {
  transform: translate3d(-58.1332px, 13.29168px, 242.78357px);
  color: #ff7500;
}
.mommy span:nth-child(23):before {
  animation-delay: 0s, -0.15333s;
}

.mommy span:nth-child(24) {
  transform: translate3d(-61.22048px, -10.83833px, 242.14579px);
  color: #ff7a00;
}
.mommy span:nth-child(24):before {
  animation-delay: 0s, -0.16s;
}

.mommy span:nth-child(25) {
  transform: translate3d(-54.29192px, -35.20076px, 241.48146px);
  color: #ff8000;
}
.mommy span:nth-child(25):before {
  animation-delay: 0s, -0.16667s;
}

.mommy span:nth-child(26) {
  transform: translate3d(-37.71495px, -55.65474px, 240.79064px);
  color: #ff8500;
}
.mommy span:nth-child(26):before {
  animation-delay: 0s, -0.17333s;
}

.mommy span:nth-child(27) {
  transform: translate3d(-13.55408px, -68.41812px, 240.07342px);
  color: #ff8a00;
}
.mommy span:nth-child(27):before {
  animation-delay: 0s, -0.18s;
}

.mommy span:nth-child(28) {
  transform: translate3d(14.66872px, -70.75337px, 239.32987px);
  color: #ff8f00;
}
.mommy span:nth-child(28):before {
  animation-delay: 0s, -0.18667s;
}

.mommy span:nth-child(29) {
  transform: translate3d(42.48545px, -61.51483px, 238.56008px);
  color: #ff9400;
}
.mommy span:nth-child(29):before {
  animation-delay: 0s, -0.19333s;
}

.mommy span:nth-child(30) {
  transform: translate3d(65.1913px, -41.45254px, 237.76413px);
  color: #ff9900;
}
.mommy span:nth-child(30):before {
  animation-delay: 0s, -0.2s;
}

.mommy span:nth-child(31) {
  transform: translate3d(78.6388px, -13.20525px, 236.9421px);
  color: #ff9e00;
}
.mommy span:nth-child(31):before {
  animation-delay: 0s, -0.20667s;
}

.mommy span:nth-child(32) {
  transform: translate3d(79.98305px, 19.03396px, 236.09409px);
  color: #ffa300;
}
.mommy span:nth-child(32):before {
  animation-delay: 0s, -0.21333s;
}

.mommy span:nth-child(33) {
  transform: translate3d(68.24586px, 50.13944px, 235.22019px);
  color: #ffa800;
}
.mommy span:nth-child(33):before {
  animation-delay: 0s, -0.22s;
}

.mommy span:nth-child(34) {
  transform: translate3d(44.59143px, 74.86995px, 234.3205px);
  color: #ffad00;
}
.mommy span:nth-child(34):before {
  animation-delay: 0s, -0.22667s;
}

.mommy span:nth-child(35) {
  transform: translate3d(12.25056px, 88.75048px, 233.39511px);
  color: #ffb300;
}
.mommy span:nth-child(35):before {
  animation-delay: 0s, -0.23333s;
}

.mommy span:nth-child(36) {
  transform: translate3d(-23.91129px, 88.87058px, 232.44412px);
  color: #ffb800;
}
.mommy span:nth-child(36):before {
  animation-delay: 0s, -0.24s;
}

.mommy span:nth-child(37) {
  transform: translate3d(-58.12632px, 74.45845px, 231.46765px);
  color: #ffbd00;
}
.mommy span:nth-child(37):before {
  animation-delay: 0s, -0.24667s;
}

.mommy span:nth-child(38) {
  transform: translate3d(-84.64667px, 47.12177px, 230.46579px);
  color: #ffc200;
}
.mommy span:nth-child(38):before {
  animation-delay: 0s, -0.25333s;
}

.mommy span:nth-child(39) {
  transform: translate3d(-98.70889px, 10.69853px, 229.43866px);
  color: #ffc700;
}
.mommy span:nth-child(39):before {
  animation-delay: 0s, -0.26s;
}

.mommy span:nth-child(40) {
  transform: translate3d(-97.3788px, -29.27521px, 228.38636px);
  color: #ffcc00;
}
.mommy span:nth-child(40):before {
  animation-delay: 0s, -0.26667s;
}

.mommy span:nth-child(41) {
  transform: translate3d(-80.12864px, -66.40789px, 227.30903px);
  color: #ffd100;
}
.mommy span:nth-child(41):before {
  animation-delay: 0s, -0.27333s;
}

.mommy span:nth-child(42) {
  transform: translate3d(-49.03685px, -94.47692px, 226.20676px);
  color: #ffd600;
}
.mommy span:nth-child(42):before {
  animation-delay: 0s, -0.28s;
}

.mommy span:nth-child(43) {
  transform: translate3d(-8.5608px, -108.47048px, 225.07969px);
  color: #ffdb00;
}
.mommy span:nth-child(43):before {
  animation-delay: 0s, -0.28667s;
}

.mommy span:nth-child(44) {
  transform: translate3d(35.0977px, -105.47241px, 223.92794px);
  color: #ffe000;
}
.mommy span:nth-child(44):before {
  animation-delay: 0s, -0.29333s;
}

.mommy span:nth-child(45) {
  transform: translate3d(74.94438px, -85.23527px, 222.75163px);
  color: #ffe600;
}
.mommy span:nth-child(45):before {
  animation-delay: 0s, -0.3s;
}

.mommy span:nth-child(46) {
  transform: translate3d(104.31576px, -50.33313px, 221.55089px);
  color: #ffeb00;
}
.mommy span:nth-child(46):before {
  animation-delay: 0s, -0.30667s;
}

.mommy span:nth-child(47) {
  transform: translate3d(117.99266px, -5.85203px, 220.32586px);
  color: #fff000;
}
.mommy span:nth-child(47):before {
  animation-delay: 0s, -0.31333s;
}

.mommy span:nth-child(48) {
  transform: translate3d(113.11821px, 41.34831px, 219.07667px);
  color: #fff500;
}
.mommy span:nth-child(48):before {
  animation-delay: 0s, -0.32s;
}

.mommy span:nth-child(49) {
  transform: translate3d(89.76004px, 83.69463px, 217.80345px);
  color: #fffa00;
}
.mommy span:nth-child(49):before {
  animation-delay: 0s, -0.32667s;
}

.mommy span:nth-child(50) {
  transform: translate3d(51.01026px, 114.11816px, 216.50635px);
  color: yellow;
}
.mommy span:nth-child(50):before {
  animation-delay: 0s, -0.33333s;
}

.mommy span:nth-child(51) {
  transform: translate3d(2.58986px, 127.234px, 215.18551px);
  color: #faff00;
}
.mommy span:nth-child(51):before {
  animation-delay: 0s, -0.34s;
}

.mommy span:nth-child(52) {
  transform: translate3d(-47.99434px, 120.28525px, 213.84107px);
  color: #f5ff00;
}
.mommy span:nth-child(52):before {
  animation-delay: 0s, -0.34667s;
}

.mommy span:nth-child(53) {
  transform: translate3d(-92.6163px, 93.68763px, 212.47317px);
  color: #f0ff00;
}
.mommy span:nth-child(53):before {
  animation-delay: 0s, -0.35333s;
}

.mommy span:nth-child(54) {
  transform: translate3d(-123.83919px, 51.07106px, 211.08198px);
  color: #ebff00;
}
.mommy span:nth-child(54):before {
  animation-delay: 0s, -0.36s;
}

.mommy span:nth-child(55) {
  transform: translate3d(-136.15442px, -1.20519px, 209.66764px);
  color: #e6ff00;
}
.mommy span:nth-child(55):before {
  animation-delay: 0s, -0.36667s;
}

.mommy span:nth-child(56) {
  transform: translate3d(-126.94498px, -55.00099px, 208.23031px);
  color: #e0ff00;
}
.mommy span:nth-child(56):before {
  animation-delay: 0s, -0.37333s;
}

.mommy span:nth-child(57) {
  transform: translate3d(-97.00574px, -101.66609px, 206.77014px);
  color: #dbff00;
}
.mommy span:nth-child(57):before {
  animation-delay: 0s, -0.38s;
}

.mommy span:nth-child(58) {
  transform: translate3d(-50.52153px, -133.43425px, 205.2873px);
  color: #d6ff00;
}
.mommy span:nth-child(58):before {
  animation-delay: 0s, -0.38667s;
}

.mommy span:nth-child(59) {
  transform: translate3d(5.50982px, -144.71544px, 203.78195px);
  color: #d1ff00;
}
.mommy span:nth-child(59):before {
  animation-delay: 0s, -0.39333s;
}

.mommy span:nth-child(60) {
  transform: translate3d(62.33154px, -133.0714px, 202.25425px);
  color: #ccff00;
}
.mommy span:nth-child(60):before {
  animation-delay: 0s, -0.4s;
}

.mommy span:nth-child(61) {
  transform: translate3d(110.79998px, -99.70517px, 200.70437px);
  color: #c7ff00;
}
.mommy span:nth-child(61):before {
  animation-delay: 0s, -0.40667s;
}

.mommy span:nth-child(62) {
  transform: translate3d(142.85929px, -49.37083px, 199.13248px);
  color: #c2ff00;
}
.mommy span:nth-child(62):before {
  animation-delay: 0s, -0.41333s;
}

.mommy span:nth-child(63) {
  transform: translate3d(152.88031px, 10.29808px, 197.53875px);
  color: #bdff00;
}
.mommy span:nth-child(63):before {
  animation-delay: 0s, -0.42s;
}

.mommy span:nth-child(64) {
  transform: translate3d(138.64118px, 69.94754px, 195.92336px);
  color: #b8ff00;
}
.mommy span:nth-child(64):before {
  animation-delay: 0s, -0.42667s;
}

.mommy span:nth-child(65) {
  transform: translate3d(101.77988px, 119.9734px, 194.28649px);
  color: #b3ff00;
}
.mommy span:nth-child(65):before {
  animation-delay: 0s, -0.43333s;
}

.mommy span:nth-child(66) {
  transform: translate3d(47.63117px, 152.07105px, 192.62831px);
  color: #adff00;
}
.mommy span:nth-child(66):before {
  animation-delay: 0s, -0.44s;
}

.mommy span:nth-child(67) {
  transform: translate3d(-15.54148px, 160.61426px, 190.94901px);
  color: #a8ff00;
}
.mommy span:nth-child(67):before {
  animation-delay: 0s, -0.44667s;
}

.mommy span:nth-child(68) {
  transform: translate3d(-77.80901px, 143.63378px, 189.24876px);
  color: #a3ff00;
}
.mommy span:nth-child(68):before {
  animation-delay: 0s, -0.45333s;
}

.mommy span:nth-child(69) {
  transform: translate3d(-129.14148px, 103.227px, 187.52777px);
  color: #9eff00;
}
.mommy span:nth-child(69):before {
  animation-delay: 0s, -0.46s;
}

.mommy span:nth-child(70) {
  transform: translate3d(-161.02726px, 45.31784px, 185.78621px);
  color: #99ff00;
}
.mommy span:nth-child(70):before {
  animation-delay: 0s, -0.46667s;
}

.mommy span:nth-child(71) {
  transform: translate3d(-167.8846px, -21.20917px, 184.02427px);
  color: #94ff00;
}
.mommy span:nth-child(71):before {
  animation-delay: 0s, -0.47333s;
}

.mommy span:nth-child(72) {
  transform: translate3d(-148.03158px, -85.8746px, 182.24216px);
  color: #8fff00;
}
.mommy span:nth-child(72):before {
  animation-delay: 0s, -0.48s;
}

.mommy span:nth-child(73) {
  transform: translate3d(-104.04685px, -138.25932px, 180.44006px);
  color: #8aff00;
}
.mommy span:nth-child(73):before {
  animation-delay: 0s, -0.48667s;
}

.mommy span:nth-child(74) {
  transform: translate3d(-42.44904px, -169.68685px, 178.61817px);
  color: #85ff00;
}
.mommy span:nth-child(74):before {
  animation-delay: 0s, -0.49333s;
}

.mommy span:nth-child(75) {
  transform: translate3d(27.26806px, -174.66097px, 176.7767px);
  color: #80ff00;
}
.mommy span:nth-child(75):before {
  animation-delay: 0s, -0.5s;
}

.mommy span:nth-child(76) {
  transform: translate3d(94.10188px, -151.81992px, 174.91584px);
  color: #7aff00;
}
.mommy span:nth-child(76):before {
  animation-delay: 0s, -0.50667s;
}

.mommy span:nth-child(77) {
  transform: translate3d(147.28213px, -104.24294px, 173.03579px);
  color: #75ff00;
}
.mommy span:nth-child(77):before {
  animation-delay: 0s, -0.51333s;
}

.mommy span:nth-child(78) {
  transform: translate3d(178.01018px, -39.04585px, 171.13678px);
  color: #70ff00;
}
.mommy span:nth-child(78):before {
  animation-delay: 0s, -0.52s;
}

.mommy span:nth-child(79) {
  transform: translate3d(180.91541px, 33.68302px, 169.21899px);
  color: #6bff00;
}
.mommy span:nth-child(79):before {
  animation-delay: 0s, -0.52667s;
}

.mommy span:nth-child(80) {
  transform: translate3d(154.98719px, 102.44747px, 167.28265px);
  color: #66ff00;
}
.mommy span:nth-child(80):before {
  animation-delay: 0s, -0.53333s;
}

.mommy span:nth-child(81) {
  transform: translate3d(103.82192px, 156.16553px, 165.32797px);
  color: #61ff00;
}
.mommy span:nth-child(81):before {
  animation-delay: 0s, -0.54s;
}

.mommy span:nth-child(82) {
  transform: translate3d(35.13209px, 185.95922px, 163.35515px);
  color: #5cff00;
}
.mommy span:nth-child(82):before {
  animation-delay: 0s, -0.54667s;
}

.mommy span:nth-child(83) {
  transform: translate3d(-40.41701px, 186.62258px, 161.36442px);
  color: #57ff00;
}
.mommy span:nth-child(83):before {
  animation-delay: 0s, -0.55333s;
}

.mommy span:nth-child(84) {
  transform: translate3d(-110.86732px, 157.52493px, 159.356px);
  color: #52ff00;
}
.mommy span:nth-child(84):before {
  animation-delay: 0s, -0.56s;
}

.mommy span:nth-child(85) {
  transform: translate3d(-164.86574px, 102.79362px, 157.3301px);
  color: #4dff00;
}
.mommy span:nth-child(85):before {
  animation-delay: 0s, -0.56667s;
}

.mommy span:nth-child(86) {
  transform: translate3d(-193.49773px, 30.73422px, 155.28695px);
  color: #47ff00;
}
.mommy span:nth-child(86):before {
  animation-delay: 0s, -0.57333s;
}

.mommy span:nth-child(87) {
  transform: translate3d(-191.75981px, -47.43135px, 153.22676px);
  color: #42ff00;
}
.mommy span:nth-child(87):before {
  animation-delay: 0s, -0.58s;
}

.mommy span:nth-child(88) {
  transform: translate3d(-159.42781px, -119.31689px, 151.14978px);
  color: #3dff00;
}
.mommy span:nth-child(88):before {
  animation-delay: 0s, -0.58667s;
}

.mommy span:nth-child(89) {
  transform: translate3d(-101.17091px, -173.33982px, 149.05622px);
  color: #38ff00;
}
.mommy span:nth-child(89):before {
  animation-delay: 0s, -0.59333s;
}

.mommy span:nth-child(90) {
  transform: translate3d(-25.8812px, -200.59149px, 146.94631px);
  color: #33ff00;
}
.mommy span:nth-child(90):before {
  animation-delay: 0s, -0.6s;
}

.mommy span:nth-child(91) {
  transform: translate3d(54.68581px, -196.30727px, 144.82029px);
  color: #2eff00;
}
.mommy span:nth-child(91):before {
  animation-delay: 0s, -0.60667s;
}

.mommy span:nth-child(92) {
  transform: translate3d(127.75141px, -160.69367px, 142.67839px);
  color: #29ff00;
}
.mommy span:nth-child(92):before {
  animation-delay: 0s, -0.61333s;
}

.mommy span:nth-child(93) {
  transform: translate3d(181.54584px, -98.96969px, 140.52084px);
  color: #24ff00;
}
.mommy span:nth-child(93):before {
  animation-delay: 0s, -0.62s;
}

.mommy span:nth-child(94) {
  transform: translate3d(207.20841px, -20.60432px, 138.34789px);
  color: #1fff00;
}
.mommy span:nth-child(94):before {
  animation-delay: 0s, -0.62667s;
}

.mommy span:nth-child(95) {
  transform: translate3d(200.24804px, 62.1389px, 136.15976px);
  color: #1aff00;
}
.mommy span:nth-child(95):before {
  animation-delay: 0s, -0.63333s;
}

.mommy span:nth-child(96) {
  transform: translate3d(161.32357px, 136.12608px, 133.9567px);
  color: #14ff00;
}
.mommy span:nth-child(96):before {
  animation-delay: 0s, -0.64s;
}

.mommy span:nth-child(97) {
  transform: translate3d(96.20879px, 189.44318px, 131.73895px);
  color: #0fff00;
}
.mommy span:nth-child(97):before {
  animation-delay: 0s, -0.64667s;
}

.mommy span:nth-child(98) {
  transform: translate3d(14.93706px, 213.31874px, 129.50675px);
  color: #0aff00;
}
.mommy span:nth-child(98):before {
  animation-delay: 0s, -0.65333s;
}

.mommy span:nth-child(99) {
  transform: translate3d(-69.74806px, 203.5682px, 127.26035px);
  color: #05ff00;
}
.mommy span:nth-child(99):before {
  animation-delay: 0s, -0.66s;
}

.mommy span:nth-child(100) {
  transform: translate3d(-144.39633px, 161.32173px, 125px);
  color: lime;
}
.mommy span:nth-child(100):before {
  animation-delay: 0s, -0.66667s;
}

.mommy span:nth-child(101) {
  transform: translate3d(-196.99263px, 92.90989px, 122.72594px);
  color: #00ff05;
}
.mommy span:nth-child(101):before {
  animation-delay: 0s, -0.67333s;
}

.mommy span:nth-child(102) {
  transform: translate3d(-218.89521px, 8.91494px, 120.43842px);
  color: #00ff0a;
}
.mommy span:nth-child(102):before {
  animation-delay: 0s, -0.68s;
}

.mommy span:nth-child(103) {
  transform: translate3d(-206.2569px, -77.46984px, 118.13769px);
  color: #00ff0f;
}
.mommy span:nth-child(103):before {
  animation-delay: 0s, -0.68667s;
}

.mommy span:nth-child(104) {
  transform: translate3d(-160.69556px, -152.51799px, 115.82401px);
  color: #00ff14;
}
.mommy span:nth-child(104):before {
  animation-delay: 0s, -0.69333s;
}

.mommy span:nth-child(105) {
  transform: translate3d(-89.09738px, -204.15667px, 113.49762px);
  color: #00ff1a;
}
.mommy span:nth-child(105):before {
  animation-delay: 0s, -0.7s;
}

.mommy span:nth-child(106) {
  transform: translate3d(-2.5753px, -223.91313px, 111.15879px);
  color: #00ff1f;
}
.mommy span:nth-child(106):before {
  animation-delay: 0s, -0.70667s;
}

.mommy span:nth-child(107) {
  transform: translate3d(85.26016px, -208.30644px, 108.80777px);
  color: #00ff24;
}
.mommy span:nth-child(107):before {
  animation-delay: 0s, -0.71333s;
}

.mommy span:nth-child(108) {
  transform: translate3d(160.44758px, -159.45555px, 106.44482px);
  color: #00ff29;
}
.mommy span:nth-child(108):before {
  animation-delay: 0s, -0.72s;
}

.mommy span:nth-child(109) {
  transform: translate3d(210.89962px, -84.79826px, 104.0702px);
  color: #00ff2e;
}
.mommy span:nth-child(109):before {
  animation-delay: 0s, -0.72667s;
}

.mommy span:nth-child(110) {
  transform: translate3d(228.35058px, 4.04288px, 101.68416px);
  color: #00ff33;
}
.mommy span:nth-child(110):before {
  animation-delay: 0s, -0.73333s;
}

.mommy span:nth-child(111) {
  transform: translate3d(209.71226px, 93.07452px, 99.28697px);
  color: #00ff38;
}
.mommy span:nth-child(111):before {
  animation-delay: 0s, -0.74s;
}

.mommy span:nth-child(112) {
  transform: translate3d(157.61531px, 168.14248px, 96.8789px);
  color: #00ff3d;
}
.mommy span:nth-child(112):before {
  animation-delay: 0s, -0.74667s;
}

.mommy span:nth-child(113) {
  transform: translate3d(80.042px, 217.18782px, 94.4602px);
  color: #00ff42;
}
.mommy span:nth-child(113):before {
  animation-delay: 0s, -0.75333s;
}

.mommy span:nth-child(114) {
  transform: translate3d(-10.89915px, 232.18845px, 92.03114px);
  color: #00ff47;
}
.mommy span:nth-child(114):before {
  animation-delay: 0s, -0.76s;
}

.mommy span:nth-child(115) {
  transform: translate3d(-100.86822px, 210.47299px, 89.59199px);
  color: #00ff4d;
}
.mommy span:nth-child(115):before {
  animation-delay: 0s, -0.76667s;
}

.mommy span:nth-child(116) {
  transform: translate3d(-175.56116px, 155.19142px, 87.14301px);
  color: #00ff52;
}
.mommy span:nth-child(116):before {
  animation-delay: 0s, -0.77333s;
}

.mommy span:nth-child(117) {
  transform: translate3d(-222.98983px, 74.86036px, 84.68448px);
  color: #00ff57;
}
.mommy span:nth-child(117):before {
  animation-delay: 0s, -0.78s;
}

.mommy span:nth-child(118) {
  transform: translate3d(-235.4106px, -17.95182px, 82.21666px);
  color: #00ff5c;
}
.mommy span:nth-child(118):before {
  animation-delay: 0s, -0.78667s;
}

.mommy span:nth-child(119) {
  transform: translate3d(-210.59045px, -108.5966px, 79.73983px);
  color: #00ff61;
}
.mommy span:nth-child(119):before {
  animation-delay: 0s, -0.79333s;
}

.mommy span:nth-child(120) {
  transform: translate3d(-152.20336px, -182.6634px, 77.25425px);
  color: #00ff66;
}
.mommy span:nth-child(120):before {
  animation-delay: 0s, -0.8s;
}

.mommy span:nth-child(121) {
  transform: translate3d(-69.28728px, -228.27656px, 74.7602px);
  color: #00ff6b;
}
.mommy span:nth-child(121):before {
  animation-delay: 0s, -0.80667s;
}

.mommy span:nth-child(122) {
  transform: translate3d(25.15819px, -238.0039px, 72.25795px);
  color: #00ff70;
}
.mommy span:nth-child(122):before {
  animation-delay: 0s, -0.81333s;
}

.mommy span:nth-child(123) {
  transform: translate3d(116.21525px, -210.06966px, 69.74778px);
  color: #00ff75;
}
.mommy span:nth-child(123):before {
  animation-delay: 0s, -0.82s;
}

.mommy span:nth-child(124) {
  transform: translate3d(189.41049px, -148.67346px, 67.22996px);
  color: #00ff7a;
}
.mommy span:nth-child(124):before {
  animation-delay: 0s, -0.82667s;
}

.mommy span:nth-child(125) {
  transform: translate3d(233.0214px, -63.35866px, 64.70476px);
  color: #00ff80;
}
.mommy span:nth-child(125):before {
  animation-delay: 0s, -0.83333s;
}

.mommy span:nth-child(126) {
  transform: translate3d(239.95828px, 32.47471px, 62.17247px);
  color: #00ff85;
}
.mommy span:nth-child(126):before {
  animation-delay: 0s, -0.84s;
}

.mommy span:nth-child(127) {
  transform: translate3d(208.91878px, 123.68025px, 59.63336px);
  color: #00ff8a;
}
.mommy span:nth-child(127):before {
  animation-delay: 0s, -0.84667s;
}

.mommy span:nth-child(128) {
  transform: translate3d(144.62674px, 195.76542px, 57.08772px);
  color: #00ff8f;
}
.mommy span:nth-child(128):before {
  animation-delay: 0s, -0.85333s;
}

.mommy span:nth-child(129) {
  transform: translate3d(57.11222px, 237.20042px, 54.53581px);
  color: #00ff94;
}
.mommy span:nth-child(129):before {
  animation-delay: 0s, -0.86s;
}

.mommy span:nth-child(130) {
  transform: translate3d(-39.85726px, 241.26685px, 51.97792px);
  color: #00ff99;
}
.mommy span:nth-child(130):before {
  animation-delay: 0s, -0.86667s;
}

.mommy span:nth-child(131) {
  transform: translate3d(-130.94838px, 207.14909px, 49.41434px);
  color: #00ff9e;
}
.mommy span:nth-child(131):before {
  animation-delay: 0s, -0.87333s;
}

.mommy span:nth-child(132) {
  transform: translate3d(-201.69306px, 140.09077px, 46.84533px);
  color: #00ffa3;
}
.mommy span:nth-child(132):before {
  animation-delay: 0s, -0.88s;
}

.mommy span:nth-child(133) {
  transform: translate3d(-240.79242px, 50.58726px, 44.27119px);
  color: #00ffa8;
}
.mommy span:nth-child(133):before {
  animation-delay: 0s, -0.88667s;
}

.mommy span:nth-child(134) {
  transform: translate3d(-241.92587px, -47.26134px, 41.69219px);
  color: #00ffad;
}
.mommy span:nth-child(134):before {
  animation-delay: 0s, -0.89333s;
}

.mommy span:nth-child(135) {
  transform: translate3d(-204.77491px, -137.97736px, 39.10862px);
  color: #00ffb3;
}
.mommy span:nth-child(135):before {
  animation-delay: 0s, -0.9s;
}

.mommy span:nth-child(136) {
  transform: translate3d(-135.09558px, -207.16037px, 36.52076px);
  color: #00ffb8;
}
.mommy span:nth-child(136):before {
  animation-delay: 0s, -0.90667s;
}

.mommy span:nth-child(137) {
  transform: translate3d(-43.82449px, -243.77909px, 33.92889px);
  color: #00ffbd;
}
.mommy span:nth-child(137):before {
  animation-delay: 0s, -0.91333s;
}

.mommy span:nth-child(138) {
  transform: translate3d(54.6423px, -241.93479px, 31.33331px);
  color: #00ffc2;
}
.mommy span:nth-child(138):before {
  animation-delay: 0s, -0.92s;
}

.mommy span:nth-child(139) {
  transform: translate3d(144.72603px, -201.81357px, 28.73429px);
  color: #00ffc7;
}
.mommy span:nth-child(139):before {
  animation-delay: 0s, -0.92667s;
}

.mommy span:nth-child(140) {
  transform: translate3d(212.13652px, -129.67347px, 26.13212px);
  color: #00ffcc;
}
.mommy span:nth-child(140):before {
  animation-delay: 0s, -0.93333s;
}

.mommy span:nth-child(141) {
  transform: translate3d(246.14505px, -36.86584px, 23.52708px);
  color: #00ffd1;
}
.mommy span:nth-child(141):before {
  animation-delay: 0s, -0.94s;
}

.mommy span:nth-child(142) {
  transform: translate3d(241.29625px, 61.95559px, 20.91946px);
  color: #00ffd6;
}
.mommy span:nth-child(142):before {
  animation-delay: 0s, -0.94667s;
}

.mommy span:nth-child(143) {
  transform: translate3d(198.28528px, 151.15459px, 18.30955px);
  color: #00ffdb;
}
.mommy span:nth-child(143):before {
  animation-delay: 0s, -0.95333s;
}

.mommy span:nth-child(144) {
  transform: translate3d(123.85886px, 216.59309px, 15.69763px);
  color: #00ffe0;
}
.mommy span:nth-child(144):before {
  animation-delay: 0s, -0.96s;
}

.mommy span:nth-child(145) {
  transform: translate3d(29.7542px, 247.87799px, 13.08399px);
  color: #00ffe6;
}
.mommy span:nth-child(145):before {
  animation-delay: 0s, -0.96667s;
}

.mommy span:nth-child(146) {
  transform: translate3d(-69.15695px, 240.01608px, 10.46891px);
  color: #00ffeb;
}
.mommy span:nth-child(146):before {
  animation-delay: 0s, -0.97333s;
}

.mommy span:nth-child(147) {
  transform: translate3d(-157.22479px, 194.21303px, 7.85269px);
  color: #00fff0;
}
.mommy span:nth-child(147):before {
  animation-delay: 0s, -0.98s;
}

.mommy span:nth-child(148) {
  transform: translate3d(-220.5042px, 117.6881px, 5.2356px);
  color: #00fff5;
}
.mommy span:nth-child(148):before {
  animation-delay: 0s, -0.98667s;
}

.mommy span:nth-child(149) {
  transform: translate3d(-248.96867px, 22.53324px, 2.61795px);
  color: #00fffa;
}
.mommy span:nth-child(149):before {
  animation-delay: 0s, -0.99333s;
}

.mommy span:nth-child(150) {
  transform: translate3d(-238.10325px, -76.20266px, 0px);
  color: cyan;
}
.mommy span:nth-child(150):before {
  animation-delay: 0s, -1s;
}

.mommy span:nth-child(151) {
  transform: translate3d(-189.6225px, -162.90013px, -2.61795px);
  color: #00faff;
}
.mommy span:nth-child(151):before {
  animation-delay: 0s, -1.00667s;
}

.mommy span:nth-child(152) {
  transform: translate3d(-111.1993px, -223.84661px, -5.2356px);
  color: #00f5ff;
}
.mommy span:nth-child(152):before {
  animation-delay: 0s, -1.01333s;
}

.mommy span:nth-child(153) {
  transform: translate3d(-15.24718px, -249.41102px, -7.85269px);
  color: #00f0ff;
}
.mommy span:nth-child(153):before {
  animation-delay: 0s, -1.02s;
}

.mommy span:nth-child(154) {
  transform: translate3d(83.04975px, -235.56982px, -10.46891px);
  color: #00ebff;
}
.mommy span:nth-child(154):before {
  animation-delay: 0s, -1.02667s;
}

.mommy span:nth-child(155) {
  transform: translate3d(168.14604px, -184.54192px, -13.08399px);
  color: #00e6ff;
}
.mommy span:nth-child(155):before {
  animation-delay: 0s, -1.03333s;
}

.mommy span:nth-child(156) {
  transform: translate3d(226.5999px, -104.43214px, -15.69763px);
  color: #00e0ff;
}
.mommy span:nth-child(156):before {
  animation-delay: 0s, -1.04s;
}

.mommy span:nth-child(157) {
  transform: translate3d(249.20214px, -7.94054px, -18.30955px);
  color: #00dbff;
}
.mommy span:nth-child(157):before {
  animation-delay: 0s, -1.04667s;
}

.mommy span:nth-child(158) {
  transform: translate3d(232.43092px, 89.65624px, -20.91946px);
  color: #00d6ff;
}
.mommy span:nth-child(158):before {
  animation-delay: 0s, -1.05333s;
}

.mommy span:nth-child(159) {
  transform: translate3d(179.0019px, 172.93004px, -23.52708px);
  color: #00d1ff;
}
.mommy span:nth-child(159):before {
  animation-delay: 0s, -1.06s;
}

.mommy span:nth-child(160) {
  transform: translate3d(97.42765px, 228.74651px, -26.13212px);
  color: #00ccff;
}
.mommy span:nth-child(160):before {
  animation-delay: 0s, -1.06667s;
}

.mommy span:nth-child(161) {
  transform: translate3d(0.65796px, 248.34232px, -28.73429px);
  color: #00c7ff;
}
.mommy span:nth-child(161):before {
  animation-delay: 0s, -1.07333s;
}

.mommy span:nth-child(162) {
  transform: translate3d(-95.98132px, 228.70463px, -31.33331px);
  color: #00c2ff;
}
.mommy span:nth-child(162):before {
  animation-delay: 0s, -1.08s;
}

.mommy span:nth-child(163) {
  transform: translate3d(-177.22193px, 173.03531px, -33.92889px);
  color: #00bdff;
}
.mommy span:nth-child(163):before {
  animation-delay: 0s, -1.08667s;
}

.mommy span:nth-child(164) {
  transform: translate3d(-230.27188px, 90.22802px, -36.52076px);
  color: #00b8ff;
}
.mommy span:nth-child(164):before {
  animation-delay: 0s, -1.09333s;
}

.mommy span:nth-child(165) {
  transform: translate3d(-246.83503px, -6.55607px, -39.10862px);
  color: #00b3ff;
}
.mommy span:nth-child(165):before {
  animation-delay: 0s, -1.1s;
}

.mommy span:nth-child(166) {
  transform: translate3d(-224.4119px, -101.98558px, -41.69219px);
  color: #00adff;
}
.mommy span:nth-child(166):before {
  animation-delay: 0s, -1.10667s;
}

.mommy span:nth-child(167) {
  transform: translate3d(-166.67708px, -180.99396px, -44.27119px);
  color: #00a8ff;
}
.mommy span:nth-child(167):before {
  animation-delay: 0s, -1.11333s;
}

.mommy span:nth-child(168) {
  transform: translate3d(-82.87638px, -231.16449px, -46.84533px);
  color: #00a3ff;
}
.mommy span:nth-child(168):before {
  animation-delay: 0s, -1.12s;
}

.mommy span:nth-child(169) {
  transform: translate3d(13.6574px, -244.68694px, -49.41434px);
  color: #009eff;
}
.mommy span:nth-child(169):before {
  animation-delay: 0s, -1.12667s;
}

.mommy span:nth-child(170) {
  transform: translate3d(107.63121px, -219.57645px, -51.97792px);
  color: #0099ff;
}
.mommy span:nth-child(170):before {
  animation-delay: 0s, -1.13333s;
}

.mommy span:nth-child(171) {
  transform: translate3d(184.2209px, -159.96408px, -54.53581px);
  color: #0094ff;
}
.mommy span:nth-child(171):before {
  animation-delay: 0s, -1.14s;
}

.mommy span:nth-child(172) {
  transform: translate3d(231.41593px, -75.41658px, -57.08772px);
  color: #008fff;
}
.mommy span:nth-child(172):before {
  animation-delay: 0s, -1.14667s;
}

.mommy span:nth-child(173) {
  transform: translate3d(241.90783px, 20.60248px, -59.63336px);
  color: #008aff;
}
.mommy span:nth-child(173):before {
  animation-delay: 0s, -1.15333s;
}

.mommy span:nth-child(174) {
  transform: translate3d(214.22465px, 112.88217px, -62.17247px);
  color: #0085ff;
}
.mommy span:nth-child(174):before {
  animation-delay: 0s, -1.16s;
}

.mommy span:nth-child(175) {
  transform: translate3d(152.93484px, 186.88025px, -64.70476px);
  color: #0080ff;
}
.mommy span:nth-child(175):before {
  animation-delay: 0s, -1.16667s;
}

.mommy span:nth-child(176) {
  transform: translate3d(67.89294px, 231.02096px, -67.22996px);
  color: #007aff;
}
.mommy span:nth-child(176):before {
  animation-delay: 0s, -1.17333s;
}

.mommy span:nth-child(177) {
  transform: translate3d(-27.34855px, 238.5106px, -69.74778px);
  color: #0075ff;
}
.mommy span:nth-child(177):before {
  animation-delay: 0s, -1.18s;
}

.mommy span:nth-child(178) {
  transform: translate3d(-117.7044px, 208.38537px, -72.25795px);
  color: #0070ff;
}
.mommy span:nth-child(178):before {
  animation-delay: 0s, -1.18667s;
}

.mommy span:nth-child(179) {
  transform: translate3d(-188.9523px, 145.62946px, -74.7602px);
  color: #006bff;
}
.mommy span:nth-child(179):before {
  animation-delay: 0s, -1.19333s;
}

.mommy span:nth-child(180) {
  transform: translate3d(-229.97749px, 60.35009px, -77.25425px);
  color: #0066ff;
}
.mommy span:nth-child(180):before {
  animation-delay: 0s, -1.2s;
}

.mommy span:nth-child(181) {
  transform: translate3d(-234.51114px, -33.85389px, -79.73983px);
  color: #0061ff;
}
.mommy span:nth-child(181):before {
  animation-delay: 0s, -1.20667s;
}

.mommy span:nth-child(182) {
  transform: translate3d(-202.08986px, -122.066px, -82.21666px);
  color: #005cff;
}
.mommy span:nth-child(182):before {
  animation-delay: 0s, -1.21333s;
}

.mommy span:nth-child(183) {
  transform: translate3d(-138.08932px, -190.42027px, -84.68448px);
  color: #0057ff;
}
.mommy span:nth-child(183):before {
  animation-delay: 0s, -1.22s;
}

.mommy span:nth-child(184) {
  transform: translate3d(-52.83268px, -228.28667px, -87.14301px);
  color: #0052ff;
}
.mommy span:nth-child(184):before {
  animation-delay: 0s, -1.22667s;
}

.mommy span:nth-child(185) {
  transform: translate3d(40.07799px, -229.92832px, -89.59199px);
  color: #004dff;
}
.mommy span:nth-child(185):before {
  animation-delay: 0s, -1.23333s;
}

.mommy span:nth-child(186) {
  transform: translate3d(125.93733px, -195.37159px, -92.03114px);
  color: #0047ff;
}
.mommy span:nth-child(186):before {
  animation-delay: 0s, -1.24s;
}

.mommy span:nth-child(187) {
  transform: translate3d(191.27035px, -130.35691px, -94.4602px);
  color: #0042ff;
}
.mommy span:nth-child(187):before {
  animation-delay: 0s, -1.24667s;
}

.mommy span:nth-child(188) {
  transform: translate3d(225.95279px, -45.38519px, -96.8789px);
  color: #003dff;
}
.mommy span:nth-child(188):before {
  animation-delay: 0s, -1.25333s;
}

.mommy span:nth-child(189) {
  transform: translate3d(224.78384px, 45.98178px, -99.28697px);
  color: #0038ff;
}
.mommy span:nth-child(189):before {
  animation-delay: 0s, -1.26s;
}

.mommy span:nth-child(190) {
  transform: translate3d(188.26604px, 129.29127px, -101.68416px);
  color: #0033ff;
}
.mommy span:nth-child(190):before {
  animation-delay: 0s, -1.26667s;
}

.mommy span:nth-child(191) {
  transform: translate3d(122.47564px, 191.49181px, -104.0702px);
  color: #002eff;
}
.mommy span:nth-child(191):before {
  animation-delay: 0s, -1.27333s;
}

.mommy span:nth-child(192) {
  transform: translate3d(38.05169px, 222.98334px, -106.44482px);
  color: #0029ff;
}
.mommy span:nth-child(192):before {
  animation-delay: 0s, -1.28s;
}

.mommy span:nth-child(193) {
  transform: translate3d(-51.52785px, 219.10214px, -108.80777px);
  color: #0024ff;
}
.mommy span:nth-child(193):before {
  animation-delay: 0s, -1.28667s;
}

.mommy span:nth-child(194) {
  transform: translate3d(-132.10323px, 180.81056px, -111.15879px);
  color: #001fff;
}
.mommy span:nth-child(194):before {
  animation-delay: 0s, -1.29333s;
}

.mommy span:nth-child(195) {
  transform: translate3d(-191.07704px, 114.48954px, -113.49762px);
  color: #001aff;
}
.mommy span:nth-child(195):before {
  animation-delay: 0s, -1.3s;
}

.mommy span:nth-child(196) {
  transform: translate3d(-219.38891px, 30.87561px, -115.82401px);
  color: #0014ff;
}
.mommy span:nth-child(196):before {
  animation-delay: 0s, -1.30667s;
}

.mommy span:nth-child(197) {
  transform: translate3d(-212.9103px, -56.6806px, -118.13769px);
  color: #000fff;
}
.mommy span:nth-child(197):before {
  animation-delay: 0s, -1.31333s;
}

.mommy span:nth-child(198) {
  transform: translate3d(-173.0442px, -134.35138px, -120.43842px);
  color: #000aff;
}
.mommy span:nth-child(198):before {
  animation-delay: 0s, -1.32s;
}

.mommy span:nth-child(199) {
  transform: translate3d(-106.44313px, -190.02159px, -122.72594px);
  color: #0005ff;
}
.mommy span:nth-child(199):before {
  animation-delay: 0s, -1.32667s;
}

.mommy span:nth-child(200) {
  transform: translate3d(-23.89954px, -215.18321px, -125px);
  color: blue;
}
.mommy span:nth-child(200):before {
  animation-delay: 0s, -1.33333s;
}

.mommy span:nth-child(201) {
  transform: translate3d(61.40643px, -206.23785px, -127.26035px);
  color: #0500ff;
}
.mommy span:nth-child(201):before {
  animation-delay: 0s, -1.34s;
}

.mommy span:nth-child(202) {
  transform: translate3d(136.01672px, -165.00743px, -129.50675px);
  color: #0a00ff;
}
.mommy span:nth-child(202):before {
  animation-delay: 0s, -1.34667s;
}

.mommy span:nth-child(203) {
  transform: translate3d(188.32419px, -98.38113px, -131.73895px);
  color: #0f00ff;
}
.mommy span:nth-child(203):before {
  animation-delay: 0s, -1.35333s;
}

.mommy span:nth-child(204) {
  transform: translate3d(210.3829px, -17.165px, -133.9567px);
  color: #1400ff;
}
.mommy span:nth-child(204):before {
  animation-delay: 0s, -1.36s;
}

.mommy span:nth-child(205) {
  transform: translate3d(199.11668px, 65.67394px, -136.15976px);
  color: #1a00ff;
}
.mommy span:nth-child(205):before {
  animation-delay: 0s, -1.36667s;
}

.mommy span:nth-child(206) {
  transform: translate3d(156.74204px, 137.08316px, -138.34789px);
  color: #1f00ff;
}
.mommy span:nth-child(206):before {
  animation-delay: 0s, -1.37333s;
}

.mommy span:nth-child(207) {
  transform: translate3d(90.34827px, 185.98678px, -140.52084px);
  color: #2400ff;
}
.mommy span:nth-child(207):before {
  animation-delay: 0s, -1.38s;
}

.mommy span:nth-child(208) {
  transform: translate3d(10.71222px, 205.00762px, -142.67839px);
  color: #2900ff;
}
.mommy span:nth-child(208):before {
  animation-delay: 0s, -1.38667s;
}

.mommy span:nth-child(209) {
  transform: translate3d(-69.45406px, 191.58084px, -144.82029px);
  color: #2e00ff;
}
.mommy span:nth-child(209):before {
  animation-delay: 0s, -1.39333s;
}

.mommy span:nth-child(210) {
  transform: translate3d(-137.53764px, 148.29086px, -146.94631px);
  color: #3300ff;
}
.mommy span:nth-child(210):before {
  animation-delay: 0s, -1.4s;
}

.mommy span:nth-child(211) {
  transform: translate3d(-183.01446px, 82.38902px, -149.05622px);
  color: #3800ff;
}
.mommy span:nth-child(211):before {
  animation-delay: 0s, -1.40667s;
}

.mommy span:nth-child(212) {
  transform: translate3d(-199.0798px, 4.57997px, -151.14978px);
  color: #3d00ff;
}
.mommy span:nth-child(212):before {
  animation-delay: 0s, -1.41333s;
}

.mommy span:nth-child(213) {
  transform: translate3d(-183.66636px, -72.72019px, -153.22676px);
  color: #4200ff;
}
.mommy span:nth-child(213):before {
  animation-delay: 0s, -1.42s;
}

.mommy span:nth-child(214) {
  transform: translate3d(-139.69754px, -137.37017px, -155.28695px);
  color: #4700ff;
}
.mommy span:nth-child(214):before {
  animation-delay: 0s, -1.42667s;
}

.mommy span:nth-child(215) {
  transform: translate3d(-74.54742px, -179.4155px, -157.3301px);
  color: #4d00ff;
}
.mommy span:nth-child(215):before {
  animation-delay: 0s, -1.43333s;
}

.mommy span:nth-child(216) {
  transform: translate3d(1.19468px, -192.62461px, -159.356px);
  color: #5200ff;
}
.mommy span:nth-child(216):before {
  animation-delay: 0s, -1.44s;
}

.mommy span:nth-child(217) {
  transform: translate3d(75.44839px, -175.41113px, -161.36442px);
  color: #5700ff;
}
.mommy span:nth-child(217):before {
  animation-delay: 0s, -1.44667s;
}

.mommy span:nth-child(218) {
  transform: translate3d(136.57388px, -131.00637px, -163.35515px);
  color: #5c00ff;
}
.mommy span:nth-child(218):before {
  animation-delay: 0s, -1.45333s;
}

.mommy span:nth-child(219) {
  transform: translate3d(175.20129px, -66.86683px, -165.32797px);
  color: #6100ff;
}
.mommy span:nth-child(219):before {
  animation-delay: 0s, -1.46s;
}

.mommy span:nth-child(220) {
  transform: translate3d(185.66977px, 6.57652px, -167.28265px);
  color: #6600ff;
}
.mommy span:nth-child(220):before {
  animation-delay: 0s, -1.46667s;
}

.mommy span:nth-child(221) {
  transform: translate3d(166.85462px, 77.61744px, -169.21899px);
  color: #6b00ff;
}
.mommy span:nth-child(221):before {
  animation-delay: 0s, -1.47333s;
}

.mommy span:nth-child(222) {
  transform: translate3d(122.26205px, 135.14509px, -171.13678px);
  color: #7000ff;
}
.mommy span:nth-child(222):before {
  animation-delay: 0s, -1.48s;
}

.mommy span:nth-child(223) {
  transform: translate3d(59.38969px, 170.38626px, -173.03579px);
  color: #7500ff;
}
.mommy span:nth-child(223):before {
  animation-delay: 0s, -1.48667s;
}

.mommy span:nth-child(224) {
  transform: translate3d(-11.53238px, 178.24549px, -174.91584px);
  color: #7a00ff;
}
.mommy span:nth-child(224):before {
  animation-delay: 0s, -1.49333s;
}

.mommy span:nth-child(225) {
  transform: translate3d(-79.20897px, 158.03778px, -176.7767px);
  color: #8000ff;
}
.mommy span:nth-child(225):before {
  animation-delay: 0s, -1.5s;
}

.mommy span:nth-child(226) {
  transform: translate3d(-133.08328px, 113.50942px, -178.61817px);
  color: #8500ff;
}
.mommy span:nth-child(226):before {
  animation-delay: 0s, -1.50667s;
}

.mommy span:nth-child(227) {
  transform: translate3d(-164.98787px, 52.15734px, -180.44006px);
  color: #8a00ff;
}
.mommy span:nth-child(227):before {
  animation-delay: 0s, -1.51333s;
}

.mommy span:nth-child(228) {
  transform: translate3d(-170.38425px, -16.03132px, -182.24216px);
  color: #8f00ff;
}
.mommy span:nth-child(228):before {
  animation-delay: 0s, -1.52s;
}

.mommy span:nth-child(229) {
  transform: translate3d(-149.00273px, -80.20757px, -184.02427px);
  color: #9400ff;
}
.mommy span:nth-child(229):before {
  animation-delay: 0s, -1.52667s;
}

.mommy span:nth-child(230) {
  transform: translate3d(-104.79329px, -130.39115px, -185.78621px);
  color: #9900ff;
}
.mommy span:nth-child(230):before {
  animation-delay: 0s, -1.53333s;
}

.mommy span:nth-child(231) {
  transform: translate3d(-45.20979px, -159.02645px, -187.52777px);
  color: #9e00ff;
}
.mommy span:nth-child(231):before {
  animation-delay: 0s, -1.54s;
}

.mommy span:nth-child(232) {
  transform: translate3d(20.04477px, -162.12067px, -189.24876px);
  color: #a300ff;
}
.mommy span:nth-child(232):before {
  animation-delay: 0s, -1.54667s;
}

.mommy span:nth-child(233) {
  transform: translate3d(80.60086px, -139.79263px, -190.94901px);
  color: #a800ff;
}
.mommy span:nth-child(233):before {
  animation-delay: 0s, -1.55333s;
}

.mommy span:nth-child(234) {
  transform: translate3d(127.07455px, -96.15817px, -192.62831px);
  color: #ad00ff;
}
.mommy span:nth-child(234):before {
  animation-delay: 0s, -1.56s;
}

.mommy span:nth-child(235) {
  transform: translate3d(152.52514px, -38.58552px, -194.28649px);
  color: #b300ff;
}
.mommy span:nth-child(235):before {
  animation-delay: 0s, -1.56667s;
}

.mommy span:nth-child(236) {
  transform: translate3d(153.49134px, 23.54666px, -195.92336px);
  color: #b800ff;
}
.mommy span:nth-child(236):before {
  animation-delay: 0s, -1.57333s;
}

.mommy span:nth-child(237) {
  transform: translate3d(130.45142px, 80.37952px, -197.53875px);
  color: #bd00ff;
}
.mommy span:nth-child(237):before {
  animation-delay: 0s, -1.58s;
}

.mommy span:nth-child(238) {
  transform: translate3d(87.64806px, 123.14249px, -199.13248px);
  color: #c200ff;
}
.mommy span:nth-child(238):before {
  animation-delay: 0s, -1.58667s;
}

.mommy span:nth-child(239) {
  transform: translate3d(32.3213px, 145.50976px, -200.70437px);
  color: #c700ff;
}
.mommy span:nth-child(239):before {
  animation-delay: 0s, -1.59333s;
}

.mommy span:nth-child(240) {
  transform: translate3d(-26.51359px, 144.53459px, -202.25425px);
  color: #cc00ff;
}
.mommy span:nth-child(240):before {
  animation-delay: 0s, -1.6s;
}

.mommy span:nth-child(241) {
  transform: translate3d(-79.53741px, 121.02362px, -203.78195px);
  color: #d100ff;
}
.mommy span:nth-child(241):before {
  animation-delay: 0s, -1.60667s;
}

.mommy span:nth-child(242) {
  transform: translate3d(-118.60709px, 79.30626px, -205.2873px);
  color: #d600ff;
}
.mommy span:nth-child(242):before {
  animation-delay: 0s, -1.61333s;
}

.mommy span:nth-child(243) {
  transform: translate3d(-138.0087px, 26.45198px, -206.77014px);
  color: #db00ff;
}
.mommy span:nth-child(243):before {
  animation-delay: 0s, -1.62s;
}

.mommy span:nth-child(244) {
  transform: translate3d(-135.29038px, -28.92492px, -208.23031px);
  color: #e000ff;
}
.mommy span:nth-child(244):before {
  animation-delay: 0s, -1.62667s;
}

.mommy span:nth-child(245) {
  transform: translate3d(-111.55409px, -78.07154px, -209.66764px);
  color: #e600ff;
}
.mommy span:nth-child(245):before {
  animation-delay: 0s, -1.63333s;
}

.mommy span:nth-child(246) {
  transform: translate3d(-71.17508px, -113.4835px, -211.08198px);
  color: #eb00ff;
}
.mommy span:nth-child(246):before {
  animation-delay: 0s, -1.64s;
}

.mommy span:nth-child(247) {
  transform: translate3d(-21.01034px, -130.05274px, -212.47317px);
  color: #f000ff;
}
.mommy span:nth-child(247):before {
  animation-delay: 0s, -1.64667s;
}

.mommy span:nth-child(248) {
  transform: translate3d(30.76289px, -125.80001px, -213.84107px);
  color: #f500ff;
}
.mommy span:nth-child(248):before {
  animation-delay: 0s, -1.65333s;
}

.mommy span:nth-child(249) {
  transform: translate3d(75.98209px, -102.0878px, -215.18551px);
  color: #fa00ff;
}
.mommy span:nth-child(249):before {
  animation-delay: 0s, -1.66s;
}

.mommy span:nth-child(250) {
  transform: translate3d(107.78986px, -63.29571px, -216.50635px);
  color: magenta;
}
.mommy span:nth-child(250):before {
  animation-delay: 0s, -1.66667s;
}

.mommy span:nth-child(251) {
  transform: translate3d(121.67496px, -16.02689px, -217.80345px);
  color: #ff00fa;
}
.mommy span:nth-child(251):before {
  animation-delay: 0s, -1.67333s;
}

.mommy span:nth-child(252) {
  transform: translate3d(116.10599px, 32.01269px, -219.07667px);
  color: #ff00f5;
}
.mommy span:nth-child(252):before {
  animation-delay: 0s, -1.68s;
}

.mommy span:nth-child(253) {
  transform: translate3d(92.66963px, 73.27247px, -220.32586px);
  color: #ff00f0;
}
.mommy span:nth-child(253):before {
  animation-delay: 0s, -1.68667s;
}

.mommy span:nth-child(254) {
  transform: translate3d(55.70792px, 101.54717px, -221.55089px);
  color: #ff00eb;
}
.mommy span:nth-child(254):before {
  animation-delay: 0s, -1.69333s;
}

.mommy span:nth-child(255) {
  transform: translate3d(11.52974px, 112.91048px, -222.75163px);
  color: #ff00e6;
}
.mommy span:nth-child(255):before {
  animation-delay: 0s, -1.7s;
}

.mommy span:nth-child(256) {
  transform: translate3d(-32.66259px, 106.25174px, -223.92794px);
  color: #ff00e0;
}
.mommy span:nth-child(256):before {
  animation-delay: 0s, -1.70667s;
}

.mommy span:nth-child(257) {
  transform: translate3d(-69.94921px, 83.3441px, -225.07969px);
  color: #ff00db;
}
.mommy span:nth-child(257):before {
  animation-delay: 0s, -1.71333s;
}

.mommy span:nth-child(258) {
  transform: translate3d(-94.77922px, 48.44996px, -226.20676px);
  color: #ff00d6;
}
.mommy span:nth-child(258):before {
  animation-delay: 0s, -1.72s;
}

.mommy span:nth-child(259) {
  transform: translate3d(-103.79637px, 7.54446px, -227.30903px);
  color: #ff00d1;
}
.mommy span:nth-child(259):before {
  animation-delay: 0s, -1.72667s;
}

.mommy span:nth-child(260) {
  transform: translate3d(-96.28148px, -32.7039px, -228.38636px);
  color: #ff00cc;
}
.mommy span:nth-child(260):before {
  animation-delay: 0s, -1.73333s;
}

.mommy span:nth-child(261) {
  transform: translate3d(-74.15521px, -66.02203px, -229.43866px);
  color: #ff00c7;
}
.mommy span:nth-child(261):before {
  animation-delay: 0s, -1.74s;
}

.mommy span:nth-child(262) {
  transform: translate3d(-41.55829px, -87.51245px, -230.46579px);
  color: #ff00c2;
}
.mommy span:nth-child(262):before {
  animation-delay: 0s, -1.74667s;
}

.mommy span:nth-child(263) {
  transform: translate3d(-4.09393px, -94.37144px, -231.46765px);
  color: #ff00bd;
}
.mommy span:nth-child(263):before {
  animation-delay: 0s, -1.75333s;
}

.mommy span:nth-child(264) {
  transform: translate3d(32.13114px, -86.2399px, -232.44412px);
  color: #ff00b8;
}
.mommy span:nth-child(264):before {
  animation-delay: 0s, -1.76s;
}

.mommy span:nth-child(265) {
  transform: translate3d(61.50369px, -65.14614px, -233.39511px);
  color: #ff00b3;
}
.mommy span:nth-child(265):before {
  animation-delay: 0s, -1.76667s;
}

.mommy span:nth-child(266) {
  transform: translate3d(79.77582px, -35.06741px, -234.3205px);
  color: #ff00ad;
}
.mommy span:nth-child(266):before {
  animation-delay: 0s, -1.77333s;
}

.mommy span:nth-child(267) {
  transform: translate3d(84.676px, -1.19826px, -235.22019px);
  color: #ff00a8;
}
.mommy span:nth-child(267):before {
  animation-delay: 0s, -1.78s;
}

.mommy span:nth-child(268) {
  transform: translate3d(76.17201px, 30.94196px, -236.09409px);
  color: #ff00a3;
}
.mommy span:nth-child(268):before {
  animation-delay: 0s, -1.78667s;
}

.mommy span:nth-child(269) {
  transform: translate3d(56.3591px, 56.41003px, -236.9421px);
  color: #ff009e;
}
.mommy span:nth-child(269):before {
  animation-delay: 0s, -1.79333s;
}

.mommy span:nth-child(270) {
  transform: translate3d(29.00971px, 71.60067px, -237.76413px);
  color: #ff0099;
}
.mommy span:nth-child(270):before {
  animation-delay: 0s, -1.8s;
}

.mommy span:nth-child(271) {
  transform: translate3d(-1.12536px, 74.75173px, -238.56008px);
  color: #ff0094;
}
.mommy span:nth-child(271):before {
  animation-delay: 0s, -1.80667s;
}

.mommy span:nth-child(272) {
  transform: translate3d(-29.13721px, 66.12287px, -239.32987px);
  color: #ff008f;
}
.mommy span:nth-child(272):before {
  animation-delay: 0s, -1.81333s;
}

.mommy span:nth-child(273) {
  transform: translate3d(-50.7598px, 47.83508px, -240.07342px);
  color: #ff008a;
}
.mommy span:nth-child(273):before {
  animation-delay: 0s, -1.82s;
}

.mommy span:nth-child(274) {
  transform: translate3d(-63.02055px, 23.41531px, -240.79064px);
  color: #ff0085;
}
.mommy span:nth-child(274):before {
  animation-delay: 0s, -1.82667s;
}

.mommy span:nth-child(275) {
  transform: translate3d(-64.6414px, -2.86271px, -241.48146px);
  color: #ff0080;
}
.mommy span:nth-child(275):before {
  animation-delay: 0s, -1.83333s;
}

.mommy span:nth-child(276) {
  transform: translate3d(-56.1374px, -26.72093px, -242.14579px);
  color: #ff007a;
}
.mommy span:nth-child(276):before {
  animation-delay: 0s, -1.84s;
}

.mommy span:nth-child(277) {
  transform: translate3d(-39.61365px, -44.57462px, -242.78357px);
  color: #ff0075;
}
.mommy span:nth-child(277):before {
  animation-delay: 0s, -1.84667s;
}

.mommy span:nth-child(278) {
  transform: translate3d(-18.31186px, -54.0711px, -243.39473px);
  color: #ff0070;
}
.mommy span:nth-child(278):before {
  animation-delay: 0s, -1.85333s;
}

.mommy span:nth-child(279) {
  transform: translate3d(4.00264px, -54.38873px, -243.97919px);
  color: #ff006b;
}
.mommy span:nth-child(279):before {
  animation-delay: 0s, -1.86s;
}

.mommy span:nth-child(280) {
  transform: translate3d(23.70033px, -46.26012px, -244.5369px);
  color: #ff0066;
}
.mommy span:nth-child(280):before {
  animation-delay: 0s, -1.86667s;
}

.mommy span:nth-child(281) {
  transform: translate3d(37.87885px, -31.73277px, -245.06779px);
  color: #ff0061;
}
.mommy span:nth-child(281):before {
  animation-delay: 0s, -1.87333s;
}

.mommy span:nth-child(282) {
  transform: translate3d(44.78978px, -13.72445px, -245.57181px);
  color: #ff005c;
}
.mommy span:nth-child(282):before {
  animation-delay: 0s, -1.88s;
}

.mommy span:nth-child(283) {
  transform: translate3d(44.03808px, 4.5371px, -246.0489px);
  color: #ff0057;
}
.mommy span:nth-child(283):before {
  animation-delay: 0s, -1.88667s;
}

.mommy span:nth-child(284) {
  transform: translate3d(36.53495px, 20.08572px, -246.49901px);
  color: #ff0052;
}
.mommy span:nth-child(284):before {
  animation-delay: 0s, -1.89333s;
}

.mommy span:nth-child(285) {
  transform: translate3d(24.22859px, 30.6995px, -246.92209px);
  color: #ff004d;
}
.mommy span:nth-child(285):before {
  animation-delay: 0s, -1.9s;
}

.mommy span:nth-child(286) {
  transform: translate3d(9.67546px, 35.21578px, -247.31808px);
  color: #ff0047;
}
.mommy span:nth-child(286):before {
  animation-delay: 0s, -1.90667s;
}

.mommy span:nth-child(287) {
  transform: translate3d(-4.46118px, 33.63432px, -247.68696px);
  color: #ff0042;
}
.mommy span:nth-child(287):before {
  animation-delay: 0s, -1.91333s;
}

.mommy span:nth-child(288) {
  transform: translate3d(-15.89051px, 27.00496px, -248.02868px);
  color: #ff003d;
}
.mommy span:nth-child(288):before {
  animation-delay: 0s, -1.92s;
}

.mommy span:nth-child(289) {
  transform: translate3d(-23.06603px, 17.13527px, -248.34319px);
  color: #ff0038;
}
.mommy span:nth-child(289):before {
  animation-delay: 0s, -1.92667s;
}

.mommy span:nth-child(290) {
  transform: translate3d(-25.38976px, 6.18446px, -248.63047px);
  color: #ff0033;
}
.mommy span:nth-child(290):before {
  animation-delay: 0s, -1.93333s;
}

.mommy span:nth-child(291) {
  transform: translate3d(-23.22254px, -3.77318px, -248.89049px);
  color: #ff002e;
}
.mommy span:nth-child(291):before {
  animation-delay: 0s, -1.94s;
}

.mommy span:nth-child(292) {
  transform: translate3d(-17.7122px, -11.13112px, -249.12321px);
  color: #ff0029;
}
.mommy span:nth-child(292):before {
  animation-delay: 0s, -1.94667s;
}

.mommy span:nth-child(293) {
  transform: translate3d(-10.48481px, -15.01027px, -249.32862px);
  color: #ff0024;
}
.mommy span:nth-child(293):before {
  animation-delay: 0s, -1.95333s;
}

.mommy span:nth-child(294) {
  transform: translate3d(-3.2681px, -15.35367px, -249.50668px);
  color: #ff001f;
}
.mommy span:nth-child(294):before {
  animation-delay: 0s, -1.96s;
}

.mommy span:nth-child(295) {
  transform: translate3d(2.47457px, -12.84785px, -249.65738px);
  color: #ff001a;
}
.mommy span:nth-child(295):before {
  animation-delay: 0s, -1.96667s;
}

.mommy span:nth-child(296) {
  transform: translate3d(5.82689px, -8.69744px, -249.78071px);
  color: #ff0014;
}
.mommy span:nth-child(296):before {
  animation-delay: 0s, -1.97333s;
}

.mommy span:nth-child(297) {
  transform: translate3d(6.56624px, -4.30688px, -249.87664px);
  color: #ff000f;
}
.mommy span:nth-child(297):before {
  animation-delay: 0s, -1.98s;
}

.mommy span:nth-child(298) {
  transform: translate3d(5.15053px, -0.94001px, -249.94517px);
  color: #ff000a;
}
.mommy span:nth-child(298):before {
  animation-delay: 0s, -1.98667s;
}

.mommy span:nth-child(299) {
  transform: translate3d(2.55514px, 0.56998px, -249.98629px);
  color: #ff0005;
}
.mommy span:nth-child(299):before {
  animation-delay: 0s, -1.99333s;
}

.mommy span:nth-child(300) {
  transform: translate3d(0px, 0px, -250px);
  color: red;
}
.mommy span:nth-child(300):before {
  animation-delay: 0s, -2s;
}

@keyframes rotate {
  to {
    transform: rotateY(360deg);
  }
}
@keyframes invertRotate {
  to {
    transform: rotateY(-360deg);
  }
}
@keyframes scale {
  0%, 45%,55% {
    box-shadow: 0 0 10px 0px  currentColor;
  }
  50% {
    box-shadow: 0 0 10px 5px currentColor;
  }
}

		</style>
	</head>
	<body>
	<div class="mommy">
  <div class="daddy"><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span><span></span>
  </div>
</div>
	</body>
</html>
