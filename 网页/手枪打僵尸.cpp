<!doctype html>
<html lang="en">
 <head>
  <meta charset="UTF-8">
  <meta name="Generator" content="EditPlus®">
  <meta name="Author" content="">
  <meta name="Keywords" content="">
  <meta name="Description" content="">
  <style type="text/css">
	// Sprite Spirit Usage
// https://github.com/eliorshalev/sprite-spirit
// Set Dimensions
@mixin dimensions($width: null, $height: $width) {
  min-width: $width;
  min-height: $height;
}

// Sprite to Animate Mixin
// https://eliorshalev.github.io/sprite-spirit/
@mixin spriteSpirit($name, $url, $vertical, $width, $height, $frameNum, $duration: .8, $iteration: 0, $reverse: false) {
  $single-Y-frame: $height / $frameNum;
  $single-X-frame: $width / $frameNum;

  background-image: url($url);
  background-repeat: no-repeat;
  animation: #{$name} steps($frameNum);
  animation-duration: $duration + s;

  @if $iteration == 0 {
    animation-iteration-count: infinite;
  } @else {
    animation-iteration-count: $iteration;
  }

  @if $reverse == true {
    animation-direction: reverse;
  } @else {
    animation-direction: normal;
  }

  @if $vertical == true {
    @include dimensions($width: $width, $height: $single-Y-frame);
    background-position: 0 top;
  } @else {
    @include dimensions($width: $single-X-frame, $height: $height);
    background-position: left 0;
  }

  @keyframes #{$name} {
    to {
      @if $vertical == true {
        background-position: 0 -#{$height};
      } @else {
        background-position: -#{$width} 0;
      }
    }
  }
}

//// Vriables
// Fonts
@font-face {
  font-family: 'Cinzel';
  font-style: normal;
  font-weight: 400;
  src: local('Cinzel-Regular'), url('https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/i2BwM1Eq2JyiNOY_VrkubOvvDin1pK8aKteLpeZ5c0A.woff2') format('woff2');
  unicode-range: U+0000-00FF, U+0131, U+0152-0153, U+02C6, U+02DA, U+02DC, U+2000-206F, U+2074, U+20AC, U+2212, U+2215, U+E0FF, U+EFFD, U+F000;
}

// Canves
$canvesSizeWidth: 1024px;
$canvesSizeHeight: 550px;
// Zombies
$zombieSprite: 'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/zombie-1.png';
$zombie2Sprite: 'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/zombie-2.png';
$zombie3Sprite: 'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/zombie-3.png';
$zombie4Sprite: 'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/zombie-4.png';
$zombie5Sprite: 'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/zombie-5.png';
$zombie6Sprite: 'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/zombie-6.png';
$zombieSpriteDeath: 'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/zombie-1-death.png';
$zombie2SpriteDeath: 'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/zombie-2-death.png';
$zombie3SpriteDeath: 'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/zombie-3-death.png';
$zombie4SpriteDeath: 'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/zombie-4-death.png';
$zombie5SpriteDeath: 'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/zombie-5-death.png';
$zombie6SpriteDeath: 'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/zombie-6-death.png';
// Backgrounds
$background-1: 'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/bg-1.png';
$background-2: 'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/bg-2.png';
$background-3: 'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/bg-3.png';
$background-4: 'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/bg-4.png';
//// Mixin
// Set Dimensions
@mixin dimensions($width: null,
$height: $width) {
  width: $width;
  height: $height;
}

// Fill Position
@mixin fillPosition() {
  position: absolute;
  top: 0;
  right: 0;
  bottom: 0;
  left: 0;
}

//// Reset
%reset {
  margin: 0;
  padding: 0;
}

%flex {
  display: flex;
  justify-content: center;
  align-items: center;
}

*,
*:before,
*:after {
  box-sizing: border-box;
}

::selection {
  background: transparent;
}

html,
body {
  @include dimensions($width: 100%);
  @extend %reset;
}

body {
  @extend %reset;
  @extend %flex;
  @include dimensions($width: 100%);
  overflow: hidden;
  background: #000000;
  font-family: 'Century Gothic', AppleGothic, 'CenturyGothic', sans-serif;
  display: flex;
  justify-content: center;
  align-items: center;
  flex-direction: column;
}

//// Keyframes
// Zombie Walk
@keyframes walk {
  to {
    transform: translateX(-$canvesSizeWidth);
  }
}

// Reload Trigger Spin
@keyframes reload {
  to {
    transform: rotate(6turn);
  }
}

// Reload Ammo Spin
@keyframes reload-trigger {
  0% {
    transform: rotate(-360deg);
  }
  20% {
    transform: rotate(0deg);
  }
  100% {
    transform: rotate(0deg);
  }
}

// Blinking Text
@keyframes flash {
  0% {
    opacity: 1;
  }
  25% {
    opacity: 0.5;
  }
  50% {
    opacity: 0.8;
  }
  75% {
    opacity: 0.4;
  }
  100% {
    opacity: 0.2;
  }
}

// Bleeding Text
@keyframes dripping {
  0% {
    text-shadow: 6px 4px 0 red, -5px 5px 0 red, -3px 6px 0 red, 2px 11px 0 red;
  }
  30% {
    text-shadow: 5px 3px 0 red, -4px 4px 0 red, -2px 5px 0 red, 1px 10px 0 red;
  }
  60% {
    text-shadow: 6px 4px 0 red, -5px 5px 0 red, -3px 6px 0 red, 2px 11px 0 red;
  }
  90% {
    text-shadow: 5px 3px 0 red, -4px 4px 0 red, -2px 5px 0 red, 1px 10px 0 red;
  }
  100% {
    text-shadow: 6px 4px 0 red, -5px 5px 0 red, -3px 6px 0 red, 2px 11px 0 red;
  }
}

//// Canves
// Game Canves
#canves {
  @include dimensions($width: $canvesSizeWidth, $height: 550px);
  min-width: $canvesSizeWidth;
  min-height: $canvesSizeHeight;
  position: relative;
  overflow: hidden;
  background-color: #000000;
  cursor: crosshair;
  border-radius: 8px;
  font-family: 'Cinzel', serif;
  transition: background-image 1.3s ease;
  background-repeat: no-repeat;
  background-size: 1024px 550px;
  @for $i from 1 through 4 {
    &[data-wave="#{$i}"] {
      @if $i==1 {
        background-image: url($background-1);
      }
      @if $i==2 {
        background-image: url($background-2);
      }
      @if $i==3 {
        background-image: url($background-3);
      }
      @if $i==4 {
        background-image: url($background-4);
      }
    }
  }
  // Game Cover
  .game-cover {
    @include fillPosition();
    background: url("https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/cover.jpg");
    background-size: 1024px 550px;
    display: block;
    z-index: 100000;
  }
  // Brushed Frame
  &:after {
    @include fillPosition();
    content: '';
    pointer-events: none;
    display: block;
    background: url("https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/frame.png") no-repeat;
    background-size: cover;
    border-radius: 8px;
    z-index: 1000000;
  }
}

// Github corner Icon
.github-corner:hover .octo-arm {
  animation: octocat-wave 560ms ease-in-out
}

@keyframes octocat-wave {
  0%,
  100% {
    transform: rotate(0)
  }
  20%,
  60% {
    transform: rotate(-25deg)
  }
  40%,
  80% {
    transform: rotate(10deg)
  }
}

@media (max-width:500px) {
  .github-corner:hover .octo-arm {
    animation: none
  }
  .github-corner .octo-arm {
    animation: octocat-wave 560ms ease-in-out
  }
}

.github-corner {
  position: absolute;
  top: 0;
  right: 0;
  z-index: 10000000;
}

// Footer
#footer {
  font-size: 11px;
  color: #5a5a5a;
  margin-top: 20px;
  margin-bottom: 20px;
  line-height: 21px;
  text-align: center;
  &:hover {
    svg {
      fill: #ff0000;
    }
  }
  p {
    @extend %reset;
  }
  @media screen and (max-width: 625px) {
    text-align: center;
  }
  a {
    color: currentColor;
    text-decoration: none;
  }
  .credits {
    color: #353535;
  }
  svg {
    fill: #646464;
    width: 15px;
    transition: fill .3s ease;
  }
  .get-code.generate-code & {
    margin-bottom: 164px;
    @media screen and (max-width: 625px) {
      margin-bottom: 208px;
    }
  }
}

//// Loading
.loader {
  @include fillPosition();
  opacity: 0;
  pointer-events: none;
  z-index: 1000000;
  display: flex;
  justify-content: center;
  align-items: center;
  flex-direction: column;
  transition: opacity .3s ease;
  background: url("https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/cover.jpg");
  background-size: 1024px 550px;
  .loading & {
    opacity: 1;
  }
  .zombie-loader {
    &:before {
      content: '';
      display: block;
      animation-duration: 0.7s!important;
    }
    transform: scale(0.5);
    margin-bottom: 20px;
  }
  span {
    animation: flash 1.8s ease infinite;
    color: #ffffff;
    font-size: 9px;
    position: absolute;
    bottom: 62px;
    right: 72px;
  }
  .loading-char {
    background: radial-gradient(ellipse at center, black 0%, rgba(246, 246, 246, 0) 50%);
    position: absolute;
    bottom: -20px;
    right: 30px;
  }
}

//// Info Board
// Info Board
.info-board {
  @extend %reset;
  display: block;
  position: absolute;
  top: 35px;
  left: 35px;
  font-size: 25px;
  color: #ffffff;
  z-index: 10000;
  padding: 0;
  .intro &,
  .end-game &,
  .game-over &,
  .level-message & {
    display: none;
  }
  li {
    list-style: none;
    margin-bottom: 16px;
    &.killed-status {
      background: url("https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/icons.png") no-repeat;
      background-position: 0 0;
      background-size: 114px;
      width: 114px;
      height: 39.5px;
      padding: 0 0 10px 51px;
      font-size: 32px;
      line-height: 41px;
    }
    &.life {
      margin-top: 20px;
      margin-bottom: 9px;
      .heart-icon {
        background: url("https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/icons.png") no-repeat;
        background-position: 0 -47px;
        background-size: 114px;
        width: 24px;
        height: 23px;
        display: inline-block;
        margin-right: 15px;
        opacity: 1;
        transition: opacity .3s ease;
        &.hide {
          animation: flash .6s ease;
          opacity: 0.2;
        }
        &:last-child {
          margin-right: 0;
        }
      }
    }
    &#mute-music {
      background: url("https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/icons.png") no-repeat;
      background-position: 0 -75px;
      background-size: 114px;
      width: 25px;
      height: 25px;
      cursor: pointer;
      display: inline-block;
      margin-right: 6px;
      &.muted {
        background-position: 0 -105px;
      }
    }
    &#mute-sounds {
      background: url("https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/icons.png") no-repeat;
      background-position: -30px -73px;
      background-size: 114px;
      width: 22px;
      height: 25px;
      cursor: pointer;
      display: inline-block;
      margin-right: 6px;
      &.muted {
        background-position: -30px -104px;
      }
    }
  }
}

// Pause/Resume Icons
#pause-game {
  background: url("https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/icons.png") no-repeat;
  background-position: -60px -106px;
  background-size: 114px;
  width: 19px;
  height: 22px;
  cursor: pointer;
  position: absolute;
  top: 35px;
  right: 35px;
  z-index: 100000;
  &.paused {
    background-position: -60px -75px;
  }
  .intro &,
  .end-game &,
  .game-over &,
  .level-message & {
    display: none;
  }
  .game-paused & {
    z-index: 100000;
  }
}

//// Ammo
// Ammo
.ammo {
  background: url("https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/icons.png") no-repeat;
  background-position: 0 -134px;
  background-size: 114px;
  width: 70px;
  height: 74.5px;
  transition: transform .3s ease;
  position: absolute;
  bottom: 35px;
  right: 35px;
  z-index: 10000;
  display: block;
  .intro &,
  .end-game &,
  .game-over &,
  .level-message & {
    display: none;
  }
  // Ammo Clip States
  @for $i from 0 through 6 {
    &[data-ammo="#{$i}"] {
      @if $i==0 {
        background-position: 0px -581px;
        transform: rotate(360deg);
      }
      @if $i==1 {
        background-position: 0px -507px;
        transform: rotate(300deg);
      }
      @if $i==2 {
        background-position: 0px -432px;
        transform: rotate(240deg);
      }
      @if $i==3 {
        background-position: 0px -358px;
        transform: rotate(180deg);
      }
      @if $i==4 {
        background-position: 0 -283px;
        transform: rotate(120deg);
      }
      @if $i==5 {
        background-position: 0 -208px;
        transform: rotate(60deg);
      }
      @if $i==6 {
        background-position: 0 -134px;
      }
    }
  }
  &.reload {
    animation: reload .6s ease;
  }
}

// Reload Key Hint
.reload-key {
  @include fillPosition();
  pointer-events: none;
  display: flex;
  justify-content: center;
  align-items: center;
  font-size: 9px;
  color: #878787;
  transform: translateX(0);
  transition: transform .3s cubic-bezier(0.6, 1.14, 0.04, 1.02), opacity .3s cubic-bezier(0.6, 1.14, 0.04, 1.02);
  z-index: 100000;
  [data-ammo="6"] &,
  .intro &,
  .end-game &,
  .game-over &,
  .level-message & {
    display: none;
  }
}

// Reload Hint
.reload-hint {
  position: absolute;
  bottom: 55px;
  right: 25px;
  transform: translateX(100%);
  transition: transform .3s cubic-bezier(0.6, 1.14, 0.04, 1.02), opacity .3s cubic-bezier(0.6, 1.14, 0.04, 1.02);
  padding: 0 28px;
  color: #ffffff;
  opacity: 0;
  z-index: 1000000;
  display: block;
  &.visible {
    transform: translateX(0);
    opacity: 1;
    .reload-trigger {
      animation: reload-trigger 2s ease infinite;
    }
  }
  .intro &,
  .end-game &,
  .game-over &,
  .level-message & {
    display: none;
  }
}

// Reload Trigger
.reload-trigger {
  cursor: pointer;
  background: url("https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/icons.png") no-repeat;
  background-size: 114px;
  background-position: bottom right;
  width: 35px;
  height: 35px;
  transition: transform .3s ease;
}

//// Overlay
// Overlay Screen
.overlay-screen-levels,
.overlay-screen {
  @include fillPosition();
  background: rgba(0, 0, 0, .8);
  visibility: hidden;
  transition: visibility .3s ease, opacity .3s ease;
  z-index: 100000;
  display: flex;
  justify-content: center;
  align-items: center;
  opacity: 0;
  .end-game &,
  .game-over &,
  .level-message &,
  .game-paused & {
    visibility: visible;
    opacity: 1;
  }
}

// Overlay Title
.big-title {
  top: 115px;
  color: #ffffff;
  text-align: center;
  font-size: 128px;
  margin: 0;
  text-shadow: 5px 3px 0 red, -4px 4px 0 red, -2px 5px 0 red, 1px 10px 0 red;
  transition: opacity .3s ease, visibility .3s ease;
  animation: dripping .2s ease infinite;
  cursor: default;
  display: none;
  &:hover {
    animation: flash .3s ease infinite, dripping .2s ease infinite;
  }
  div {
    text-transform: uppercase;
    font-size: 99px;
    letter-spacing: 20px;
    display: block;
    margin-top: -73px;
    margin-left: 31px;
  }
  &.game-over-title {
    .game-over & {
      display: block;
    }
    span {
      margin-left: 18px;
    }
  }
  &.end-game-title {
    .end-game & {
      display: block;
    }
    span {
      margin-left: 19px;
    }
  }
  &.game-pause-title {
    .game-paused & {
      display: block;
    }
  }
  &.level-title {
    .level-message & {
      display: block;
    }
  }
}

// Restart Hint
.restart-hint {
  animation: flash 1.8s ease infinite;
  color: #838383;
  font-size: 23px;
  position: absolute;
  bottom: 109px;
  display: none;
  cursor: pointer;
  .end-game &,
  .game-over & {
    display: block;
  }
}

//// Zombies
// Zombie General Style
.zombie {
  position: absolute;
  bottom: 74px;
  right: 0;
  transform: translateX(400px);
  animation: walk linear infinite;
  &:before {
    content: '';
    display: block;
  }
  &.killed {
    pointer-events: none;
    transition: none;
    animation-play-state: paused;
    &:before {
      pointer-events: none;
      animation-fill-mode: forwards;
    }
  }
  .game-paused & {
    pointer-events: none;
    transition: none;
    animation-play-state: paused;
    &:before {
      pointer-events: none;
      animation-play-state: paused;
    }
  }
}

// Zombies Types
@for $i from 1 through 6 {
  .zombie-#{$i} {
    @if $i==1 {
      &:before {
        @include spriteSpirit('zombie-1',
        $zombieSprite,
        true,
        194px,
        4080px,
        16,
        .6,
        0,
        false);
      }
      &.killed {
        &:before {
          @include spriteSpirit('zombie-1-death',
          $zombieSpriteDeath,
          true,
          340px,
          5220px,
          20,
          .6,
          0,
          false);
          transform: translate(158px, 22px);
        }
      }
    }
    @if $i==2 {
      &:before {
        @include spriteSpirit('zombie-2',
        $zombie2Sprite,
        true,
        211px,
        4096px,
        16,
        .6,
        0,
        false);
      }
      &.killed {
        &:before {
          @include spriteSpirit('zombie-2-death',
          $zombie2SpriteDeath,
          true,
          347px,
          5400px,
          20,
          .6,
          0,
          false);
          transform: translate(159px, 31px);
        }
      }
    }
    @if $i==3 {
      &:before {
        @include spriteSpirit('zombie-3',
        $zombie3Sprite,
        true,
        189px,
        3744px,
        16,
        .6,
        0,
        false);
      }
      &.killed {
        &:before {
          @include spriteSpirit('zombie-3-death',
          $zombie3SpriteDeath,
          true,
          334px,
          5120px,
          20,
          .6,
          0,
          false);
          transform: translate(156px, 25px);
        }
      }
    }
    @if $i==4 {
      &:before {
        @include spriteSpirit('zombie-4',
        $zombie4Sprite,
        true,
        386px,
        6000px,
        16,
        .6,
        0,
        false);
      }
      &.killed {
        &:before {
          @include spriteSpirit('zombie-4-death',
          $zombie4SpriteDeath,
          true,
          497px,
          6416px,
          16,
          .6,
          0,
          false);
          transform: translate(65px, 45px);
        }
      }
    }
    @if $i==5 {
      &:before {
        @include spriteSpirit('zombie-5',
        $zombie5Sprite,
        true,
        386px,
        6016px,
        16,
        .6,
        0,
        false);
      }
      &.killed {
        &:before {
          @include spriteSpirit('zombie-5-death',
          $zombie5SpriteDeath,
          true,
          488px,
          6240px,
          16,
          .6,
          0,
          false);
          transform: translate(70px, 37px);
        }
      }
    }
    @if $i==6 {
      &:before {
        @include spriteSpirit('zombie-6',
        $zombie6Sprite,
        true,
        386px,
        6464px,
        16,
        .6,
        0,
        false);
      }
      &.killed {
        &:before {
          @include spriteSpirit('zombie-6-death',
          $zombie6SpriteDeath,
          true,
          510px,
          6704px,
          16,
          .6,
          0,
          false);
          transform: translate(75px, 44px);
        }
      }
    }
  }
}

// Strength Bar
.strength-bar {
  position: absolute;
  top: -15px;
  left: 50%;
  transform: translateX(-50%);
  border: 1px solid #ffffff;
  height: 5px;
  border-radius: 14px;
  opacity: 1;
  transition: opacity .3s ease;
  &.hide {
    opacity: 0;
  }
  // Strength Bar Wide per Zombie
  @for $i from 1 through 6 {
    $width: $i * 15px;
    .zombie-#{$i} & {
      width: #{$width};
    }
  }
  &:after {
    @include fillPosition();
    content: '';
    background: red;
    transition: width .3s ease;
    display: block;
    width: 0;
  }
  // Strength Bar Fill per Zombie
  @for $i from 0 through 1 {
    .zombie-1[data-strength="#{$i}"] & {
      &:after {
        @if $i==0 {
          width: 0;
        }
        @if $i==1 {
          width: 100%;
        }
      }
    }
  }
  @for $i from 0 through 2 {
    .zombie-2[data-strength="#{$i}"] & {
      &:after {
        @if $i==0 {
          width: 0;
        }
        @if $i==1 {
          width: 50%;
        }
        @if $i==2 {
          width: 100%;
        }
      }
    }
  }
  @for $i from 0 through 3 {
    .zombie-3[data-strength="#{$i}"] & {
      &:after {
        @if $i==0 {
          width: 0;
        }
        @if $i==1 {
          width: 33%;
        }
        @if $i==2 {
          width: 66%;
        }
        @if $i==3 {
          width: 100%;
        }
      }
    }
  }
  @for $i from 0 through 4 {
    .zombie-4[data-strength="#{$i}"] & {
      &:after {
        @if $i==0 {
          width: 0;
        }
        @if $i==1 {
          width: 25%;
        }
        @if $i==2 {
          width: 50%;
        }
        @if $i==3 {
          width: 75%;
        }
        @if $i==4 {
          width: 100%;
        }
      }
    }
  }
  @for $i from 0 through 5 {
    .zombie-5[data-strength="#{$i}"] & {
      &:after {
        @if $i==0 {
          width: 0;
        }
        @if $i==1 {
          width: 20%;
        }
        @if $i==2 {
          width: 40%;
        }
        @if $i==3 {
          width: 60%;
        }
        @if $i==4 {
          width: 80%;
        }
        @if $i==5 {
          width: 100%;
        }
      }
    }
  }
  @for $i from 0 through 6 {
    .zombie-6[data-strength="#{$i}"] & {
      &:after {
        @if $i==0 {
          width: 0;
        }
        @if $i==1 {
          width: 25%;
        }
        @if $i==2 {
          width: 40%;
        }
        @if $i==3 {
          width: 55%;
        }
        @if $i==4 {
          width: 70%;
        }
        @if $i==5 {
          width: 85%;
        }
        @if $i==6 {
          width: 100%;
        }
      }
    }
  }
}

// Walk Speed
@for $i from 1 through 6 {
  $random-speed: $i + 10;
  $animation-speed: $i / 2;
  .walk-speed-#{$i} {
    @if $i==1 {
      animation-duration: $random-speed + s;
      &:before {
        animation-duration: $animation-speed + s;
      }
    }
    @if $i==2 {
      animation-duration: $random-speed + s;
      &:before {
        animation-duration: $animation-speed + s;
      }
    }
    @if $i==3 {
      animation-duration: $random-speed + s;
      &:before {
        animation-duration: $animation-speed + s;
      }
    }
    @if $i==4 {
      animation-duration: $random-speed + s;
      &:before {
        animation-duration: $animation-speed + s;
      }
    }
    @if $i==5 {
      animation-duration: $random-speed + s;
      &:before {
        animation-duration: $animation-speed + s;
      }
    }
    @if $i==6 {
      animation-duration: $random-speed + s;
      &:before {
        animation-duration: $animation-speed + s;
      }
    }
  }
}

// Visibility Delay
@for $i from 1 through 6 {
  $random-speed: $i/1.5;
  .walk-delay-#{$i} {
    @if $i==1 {
      animation-delay: $random-speed + s;
    }
    @if $i==2 {
      animation-delay: $random-speed + s;
    }
    @if $i==3 {
      animation-delay: $random-speed + s;
    }
    @if $i==4 {
      animation-delay: $random-speed + s;
    }
    @if $i==5 {
      animation-delay: $random-speed + s;
    }
    @if $i==6 {
      animation-delay: $random-speed + s;
    }
  }
}
  </style>
  <title>Document</title>
 </head>
 <body>
<a href="https://github.com/eliorshalev/zombie-mayhem" class="github-corner" target="_blank"><svg width="80" height="80" viewBox="0 0 250 250" style="fill:#171717; color:#fff; position: absolute; top: 0; border: 0; right: 0"><path d="M0,0 L115,115 L130,115 L142,142 L250,250 L250,0 Z"></path><path d="M128.3,109.0 C113.8,99.7 119.0,89.6 119.0,89.6 C122.0,82.7 120.5,78.6 120.5,78.6 C119.2,72.0 123.4,76.3 123.4,76.3 C127.3,80.9 125.5,87.3 125.5,87.3 C122.9,97.6 130.6,101.9 134.4,103.2" fill="currentColor" style="transform-origin: 130px 106px" class="octo-arm"></path><path d="M115.0,115.0 C114.9,115.1 118.7,116.5 119.8,115.4 L133.7,101.6 C136.9,99.2 139.9,98.4 142.2,98.6 C133.8,88.0 127.5,74.4 143.8,58.0 C148.5,53.4 154.0,51.2 159.7,51.0 C160.3,49.4 163.2,43.6 171.4,40.1 C171.4,40.1 176.1,42.5 178.8,56.2 C183.1,58.6 187.2,61.8 190.9,65.4 C194.5,69.0 197.7,73.2 200.1,77.6 C213.8,80.2 216.3,84.9 216.3,84.9 C212.7,93.1 206.9,96.0 205.4,96.6 C205.1,102.4 203.0,107.8 198.3,112.5 C181.9,128.9 168.3,122.5 157.7,114.1 C157.9,116.9 156.7,120.9 152.7,124.9 L141.0,136.5 C139.8,137.7 141.6,141.9 141.8,141.8 Z" fill="currentColor" class="octo-body"></path></svg></a>

<div id="canves" data-wave="" class="loading intro">
      <div class="loader"><div class="loading-char"><div class="zombie-loader"></div><span>Loading</span></div></div>
      <div class="game-cover"></div>
      <div class="overlay-screen">
        <h2 class="big-title game-over-title">Game <div>Over</div></h2>
        <h2 class="big-title end-game-title">You <div>Won</div></h2>
        <span class="restart-hint">Click Here to Restart</span>
        <h2 class="big-title game-pause-title">Paused</h2>
        <h2 class="big-title level-title">Level <span></span></h2>
      </div>
      <ul class="info-board">
        <li class="killed-status"><span>0</span></li>
        <li class="life"><i class="heart-icon"></i><i class="heart-icon"></i><i class="heart-icon"></i></li>
        <li id="mute-music" data-tootik="Mute Music" data-tootik-conf="right invert"></li>
        <li id="mute-sounds" data-tootik="Mute Sounds" data-tootik-conf="right invert"></li>
      </ul>
      <div id="pause-game"></div>
      <div class="ammo" data-ammo="6"><span class="reload-key">R</span></div>
      <div class="reload-hint"><div class="reload-trigger"></div></div>
    </div>

    <div id="footer">
      <p>Handcrafted with <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 492.7 492.7" width="8" height="8"><path d="M492.7 166c0-73.5-59.6-133.1-133.1-133.1 -48 0-89.9 25.5-113.3 63.6 -23.4-38.1-65.3-63.6-113.3-63.6C59.6 33 0 92.5 0 166c0 40 17.7 75.8 45.7 100.2l188.5 188.6c3.2 3.2 7.6 5 12.1 5 4.6 0 8.9-1.8 12.1-5l188.5-188.6C475 241.8 492.7 206 492.7 166z"/></svg> by <a href="https://codepen.io/eliortabeka" target="_blank" title="Elior's Codepen">Elior Shalev Tabeka</a> | GPL License<p>
      <div class="credits"><p>Resources used building this game: <a href="https://eliorshalev.github.io/sprite-spirit/" target="_blank" title="Image Sprite to Animation using SCSS Mixin">Sprite Spirit</a> | <a href="https://eliortabeka.github.io/tootik/" target="_blank" title="Tooltips with Tootik">Tooltips</a></p></div>
    </div>
	 <script src="https://cdnjs.cloudflare.com/ajax/libs/modernizr/2.8.3/modernizr.min.js"></script>
	 <script src="https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/vendor.js"></script>
  <script src="https://code.jquery.com/jquery-3.2.1.min.js"></script>
  <div id="jsi-particle-container" class="container"></div>
  <script type="text/javascript">
	'use strict';
$(document).ready(function() {
  const ZOMBIEMAYEM = (function() {

    // Cache te DOM
    let $canves = $('#canves'),
      $overlayScreen = $canves.find('.overlay-screen'),
      $gameCover = $canves.find('.game-cover'),
      $killedTitle = $canves.find('.killed-status span'),
      $lifeIcons = $canves.find('.life'),
      $muteMusic = $canves.find('#mute-music'),
      $muteSounds = $canves.find('#mute-sounds'),
      $ammoTitle = $canves.find('.ammo'),
      $reloadHint = $canves.find('.reload-hint'),
      $reloadHintSpinner = $reloadHint.find('.reload-trigger'),
      $pasueGameTrigger = $canves.find('#pause-game');

    // Sounds
    const SHOOT_SOUND = 'SHOOT_SOUND',
      NO_AMMO_SOUND = 'NO_AMMO_SOUND',
      RELOAD_SOUND = 'RELOAD_SOUND',
      ROAR_3 = 'ROAR_3',
      ROAR_4 = 'ROAR_4',
      ROAR_5 = 'ROAR_5',
      ROAR_6 = 'ROAR_6',
      LAUGHTER = 'LAUGHTER',
      SOUNDTRACK = 'SOUNDTRACK',
      PUNCH_1 = 'PUNCH_1',
      PUNCH_2 = 'PUNCH_2',
      PUNCH_3 = 'PUNCH_3',
      PUNCH_4 = 'PUNCH_4';

    // General
    let pauseZombieTracking;

    // Game Info
    let mutedMusic = false,
      mutedSounds = false,
      gamePaused = false,
      life = 3,
      zombieKilled = 0,
      wave = 0,
      ammo = 6;

    // Random number
    const getRandom = function(min, max) {
      return Math.floor(Math.random() * (max - min + 1)) + min;
    };

    // Zombie Frequency per Level
    const WAVE_1_ZOMBIE_FRQ = getRandom(1300, 1700),
      WAVE_2_ZOMBIE_FRQ = getRandom(1500, 1900),
      WAVE_3_ZOMBIE_FRQ = getRandom(1700, 2100),
      WAVE_4_ZOMBIE_FRQ = getRandom(1800, 2400);

    // Zombie Quantity per Level
    const WAVE_1_ZOMBIE_QTY = getRandom(5, 7),
      WAVE_2_ZOMBIE_QTY = getRandom(7, 10),
      WAVE_3_ZOMBIE_QTY = getRandom(10, 14),
      WAVE_4_ZOMBIE_QTY = getRandom(14, 17),
      ALL_ZOMBIES = WAVE_1_ZOMBIE_QTY + WAVE_2_ZOMBIE_QTY + WAVE_3_ZOMBIE_QTY + WAVE_4_ZOMBIE_QTY;

    // Load sounds
    (function loadSound() {
      createjs.Sound.registerSound('https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/shoot_1.mp3', SHOOT_SOUND);
      createjs.Sound.registerSound('https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/noammo.mp3', NO_AMMO_SOUND);
      createjs.Sound.registerSound('https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/reload.mp3', RELOAD_SOUND);
      createjs.Sound.registerSound('https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/3.mp3', ROAR_3);
      createjs.Sound.registerSound('https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/4.mp3', ROAR_4);
      createjs.Sound.registerSound('https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/5.mp3', ROAR_5);
      createjs.Sound.registerSound('https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/6.mp3', ROAR_6);
      createjs.Sound.registerSound('https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/laughter.mp3', LAUGHTER);
      createjs.Sound.registerSound('https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/soundtrack.mp3', SOUNDTRACK);
      createjs.Sound.registerSound('https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/punch_2.mp3', PUNCH_2);
      createjs.Sound.registerSound('https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/punch_3.mp3', PUNCH_3);
      createjs.Sound.registerSound('https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/punch_4.mp3', PUNCH_4);
    })();

    const playSound = function(sound) {
      createjs.Sound.play(sound);
    };

    // Create Zombie
    const createZombies = function() {
      let zombieType = wave === 1 ? getRandom(1, 3) : wave === 2 ? getRandom(1, 4) : getRandom(1, 6);
      $canves.append($('<div class="zombie zombie-' + zombieType + ' walk-speed-' + getRandom(1, 6) + ' walk-delay-' + getRandom(1, 6) + '" data-strength="' + zombieType + '"><div class="strength-bar"></div></div>'));
    };

    const setHandlers = function() {
      // Shoot Handler
      $canves.on('click', function() {
        if (ammo > 0) {
          ammo--;
          if (!mutedSounds) {
            playSound(SHOOT_SOUND);
          }
          $ammoTitle.attr('data-ammo', ammo);
        }
        if (ammo === 0) {
          $reloadHint.addClass('visible');
          if (!mutedSounds) {
            playSound(NO_AMMO_SOUND);
          }
        }
      });

      // Reload Handler
      $('body').on('keydown', function(e) {
        if (e.which === 82) {
          if (ammo !== 6) {
            reload();
          }
        }
      });
      $reloadHintSpinner.on('click', function() {
        if (ammo === 0) {
          reload();
          return false;
        }
      });

      // Zombie Kill Handler
      $canves.delegate('.zombie', 'click', function(e) {
        e.stopPropagation
        if (zombieKilled >= ALL_ZOMBIES) {
          return false;
        }

        if (ammo === 0) {
          if (!mutedSounds) {
            playSound(NO_AMMO_SOUND);
          }
          return false;
        }

        let $this = $(this),
          strength = e.target.dataset.strength.toString(),
          $strengthBar = $this.find('.strength-bar');

        if (strength === '1' && strength !== 0) {
          zombieKilled++;
          $killedTitle.html(zombieKilled);
          $this.css('pointer-events', 'none');
          $strengthBar.addClass('hide');

          setTimeout(function() {
            $this.addClass('killed');
            if (!mutedSounds) {
              playSound('ROAR_' + getRandom(3, 6));
            }
          }, 220);
          setTimeout(function() {
            $this.fadeOut(function() {
              $this.remove();
            });
          }, 370);
          calcWave();
        }

        strength--;
        $this.attr('data-strength', strength);
      });
    };

    // interval function From https://thecodeship.com/web-development/alternative-to-javascript-evil-setinterval/
    const interval = function(func, wait, times) {
      const interv = function(w, t) {
        return function() {
          if (typeof t === 'undefined' || t-- > 0) {
            setTimeout(interv, w);
            try {
              func.call(null);
            } catch (e) {
              t = 0;
              throw e.toString();
            }
          }
        };
      }(wait, times);

      setTimeout(interv, wait);
    };

    // Start Waves
    const startWave = function(frequency, quantity) {
      $('body').off('keydown');
      $canves.off('click');
      $reloadHint.removeClass('visible');
      pauseZombieTracking = true;
      wave++;

      $overlayScreen.find('.level-title span').html(wave);
      $canves.addClass('level-message');
      $canves.attr('data-wave', wave);

      setTimeout(function() {
        interval(function() {
          createZombies()
        }, frequency, quantity);
      }, 1000);

      setTimeout(function() {
        $canves.removeClass('level-message');
        if (wave === 1) {
          $canves.removeClass('intro');
        }

        // Start Track Zombies
        pauseZombieTracking = false;
        trackZombies();
        setHandlers();
      }, 2200);
    };

    // End Game
    const endGame = function(endType) {
      $('body').off('keydown');
      $canves.off('click');
      pauseZombieTracking = true;
      let screenType = endType === 'lose' ? 'game-over' : 'end-game';

      $canves.addClass(screenType);
      if (!mutedMusic) {
        playSound(LAUGHTER);
      }

      $canves.find('.restart-hint').on('click', function() {
        $canves.removeClass(screenType);
        // reset game
        resetGame();
        if (endType === 'win') {
          startGame();
        } else {
          if (!mutedMusic) {
            playSound(SOUNDTRACK);
          }
          startGame();
        }
      });
    };

    // Calc Wave
    const calcWave = function() {
      if (zombieKilled === WAVE_1_ZOMBIE_QTY) {
        // Start Wave 2
        if (!mutedMusic) {
          playSound(SOUNDTRACK);
        }
        startWave(WAVE_2_ZOMBIE_FRQ, WAVE_2_ZOMBIE_QTY);
      } else if (zombieKilled === (WAVE_1_ZOMBIE_QTY + WAVE_2_ZOMBIE_QTY)) {
        // Start Wave 3
        if (!mutedMusic) {
          playSound(SOUNDTRACK);
        }
        startWave(WAVE_3_ZOMBIE_FRQ, WAVE_3_ZOMBIE_QTY);
      } else if (zombieKilled === (WAVE_1_ZOMBIE_QTY + WAVE_2_ZOMBIE_QTY + WAVE_3_ZOMBIE_QTY)) {
        // Start Wave 4
        if (!mutedMusic) {
          playSound(SOUNDTRACK);
        }
        startWave(WAVE_4_ZOMBIE_FRQ, WAVE_4_ZOMBIE_QTY);
      } else if (zombieKilled >= ALL_ZOMBIES) {
        // End Game
        endGame('win');
      }
    };

    // Track Zombies on screen
    let trackZombies = function repeatOften() {
      let $zombie = $('.zombie');

      if ($zombie.length !== 0) {
        for (let i = 0, z = $zombie.length; i < z; i++) {
          let zombieWidth = $zombie.eq(i).width() - 20;

          if ($zombie.eq(i).hasClass('tracking')) {
            if ($zombie.eq(i).position().left.toFixed() <= (-zombieWidth)) {
              $zombie.eq(i).remove();
              createZombies();
              life--;
              if (!mutedSounds) {
                playSound('PUNCH_' + getRandom(2, 4));
              }
              $lifeIcons.find('.heart-icon').not('.hide').eq(-1).addClass('hide');
            }
          } else {
            $zombie.eq(i).addClass('tracking');
          }
        }
      }

      if (life !== 0) {
        if (!pauseZombieTracking) {
          requestAnimationFrame(trackZombies);
        }
      } else {
        endGame('lose');
      }
    };

    // Reload Ammo
    const reload = function() {
      if (!mutedSounds) {
        playSound(RELOAD_SOUND);
      }
      ammo = 6;

      setTimeout(function() {
        $ammoTitle.addClass('reload');
      }, 120);
      setTimeout(function() {
        $ammoTitle.attr('data-ammo', ammo);
      }, 150);
      setTimeout(function() {
        $ammoTitle.removeClass('reload');
      }, 250);

      $reloadHint.removeClass('visible');
    };

    // Mute Music
    $muteMusic.on('click', function() {
      let $this = $(this);
      $this.toggleClass('muted');
      if (!mutedMusic) {
        createjs.Sound.stop();
        mutedMusic = true;
      } else {
        mutedMusic = false;
      }
      if (ammo !== 0) {
        ammo++;
      }
    });

    // Mute Sounds
    $muteSounds.on('click', function() {
      let $this = $(this);
      $this.toggleClass('muted');
      !mutedSounds ? mutedSounds = true : mutedSounds = false;
      if (ammo !== 0) {
        ammo++;
      }
    });

    // Pause Game
    $pasueGameTrigger.on('click', function() {
      let $this = $(this);

      if (!gamePaused) {
        $this.addClass('paused');
        $canves.addClass('game-paused');
        createjs.Sound.stop();
        $('body').off('keydown');
        $canves.off('click');
        gamePaused = true;
      } else {
        $this.removeClass('paused');
        $canves.removeClass('game-paused');
        setHandlers();
        gamePaused = false;
      }
    });

    const resetGame = function() {
      zombieKilled = 0;
      wave = 0;
      ammo = 6;
      life = 3;
      $lifeIcons.find('.heart-icon').removeClass('hide');
      $killedTitle.html(zombieKilled);
      $ammoTitle.attr('data-ammo', ammo);
      createjs.Sound.stop();
      // Clear all zombies on screen
      $('.zombie').remove();
    };

    // Start Game
    const startGame = function() {
      // reset game
      resetGame();

      // Game Cover
      $gameCover.fadeIn('slow', function() {
        $canves.attr('data-wave', '1');
      });
      setTimeout(function() {
        $gameCover.fadeOut('slow', function() {
          // Start Wave 1
          if (!mutedMusic) {
            playSound(SOUNDTRACK);
          }
          startWave(WAVE_1_ZOMBIE_FRQ, WAVE_1_ZOMBIE_QTY);
        });
      }, 2500);
    };

    // Preload from https://stackoverflow.com/a/10999147
    const preload = function(files, cb) {
      var len = files.length;
      $(files.map(function(f) {
        return '<img src="' + f + '" />';
      }).join('')).load(function() {
        if (--len === 0) {
          cb();
        }
      });
    };

    return {
      initInto: function() {
        $canves.find('.zombie-loader').addClass('zombie-' + getRandom(1, 3));
        // Preload all games graphics
        preload([
          'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/zombie-1.png',
          'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/zombie-2.png',
          'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/zombie-3.png',
          'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/bg-1.png',
          'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/bg-2.png',
          'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/bg-3.png',
          'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/bg-4.png',
          'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/frame.png',
          'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/icons.png',
          'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/zombie-1-death.png',
          'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/zombie-2-death.png',
          'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/zombie-3-death.png',
          'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/zombie-4.png',
          'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/zombie-4-death.png',
          'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/zombie-5.png',
          'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/zombie-5-death.png',
          'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/zombie-6.png',
          'https://s3-us-west-2.amazonaws.com/s.cdpn.io/250758/zombie-6-death.png'
        ], function() {
          $canves.find('.loader').remove();
          startGame();
        });
      },
      killed: zombieKilled,
      ammoLeft: ammo
    }
  })();

  // Init Game
  ZOMBIEMAYEM.initInto();
});
  </script>
 </body>
</html>
