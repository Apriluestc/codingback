<!doctype html>
<html lang="en">
 <head>
  <meta charset="UTF-8">
  <meta name="Generator" content="EditPlus®">
  <meta name="Author" content="">
  <meta name="Keywords" content="">
  <meta name="Description" content="">
  <title>花束动画</title>
  <style>
#flower1 path {
  stroke-dasharray: 165;
  stroke-dashoffset: 165;
}

#flower2 path {
  stroke-dasharray: 210;
  stroke-dashoffset: 210;
}

#flower3 path {
  stroke-dasharray: 180;
  stroke-dashoffset: 180;
}

#flower4 path {
  stroke-dasharray: 200;
  stroke-dashoffset: 200;
}

#flower5 path {
  stroke-dasharray: 150;
  stroke-dashoffset: 150;
}

#flower6 path {
  stroke-dasharray: 235;
  stroke-dashoffset: 235;
}

#flower1 path:nth-of-type(1), #flower2 path:nth-of-type(1), #flower5 path:nth-of-type(1) {
  animation: draw 2s ease-in forwards;
  animation-delay: 0.02s;
}
#flower1 path:nth-of-type(2), #flower2 path:nth-of-type(2), #flower5 path:nth-of-type(2) {
  animation: draw 2s ease-in forwards;
  animation-delay: 0.04s;
}
#flower1 path:nth-of-type(3), #flower2 path:nth-of-type(3), #flower5 path:nth-of-type(3) {
  animation: draw 2s ease-in forwards;
  animation-delay: 0.06s;
}
#flower1 path:nth-of-type(4), #flower2 path:nth-of-type(4), #flower5 path:nth-of-type(4) {
  animation: draw 2s ease-in forwards;
  animation-delay: 0.08s;
}
#flower1 path:nth-of-type(5), #flower2 path:nth-of-type(5), #flower5 path:nth-of-type(5) {
  animation: draw 2s ease-in forwards;
  animation-delay: 0.1s;
}
#flower1 path:nth-of-type(6), #flower2 path:nth-of-type(6), #flower5 path:nth-of-type(6) {
  animation: draw 2s ease-in forwards;
  animation-delay: 0.12s;
}
#flower1 path:nth-of-type(7), #flower2 path:nth-of-type(7), #flower5 path:nth-of-type(7) {
  animation: draw 2s ease-in forwards;
  animation-delay: 0.14s;
}
#flower1 path:nth-of-type(8), #flower2 path:nth-of-type(8), #flower5 path:nth-of-type(8) {
  animation: draw 2s ease-in forwards;
  animation-delay: 0.16s;
}
#flower1 path:nth-of-type(9), #flower2 path:nth-of-type(9), #flower5 path:nth-of-type(9) {
  animation: draw 2s ease-in forwards;
  animation-delay: 0.18s;
}
#flower1 path:nth-of-type(10), #flower2 path:nth-of-type(10), #flower5 path:nth-of-type(10) {
  animation: draw 2s ease-in forwards;
  animation-delay: 0.2s;
}
#flower1 path:nth-of-type(11), #flower2 path:nth-of-type(11), #flower5 path:nth-of-type(11) {
  animation: draw 2s ease-in forwards;
  animation-delay: 0.22s;
}
#flower1 path:nth-of-type(12), #flower2 path:nth-of-type(12), #flower5 path:nth-of-type(12) {
  animation: draw 2s ease-in forwards;
  animation-delay: 0.24s;
}

#flower3 path:nth-of-type(1), #flower4 path:nth-of-type(1), #flower6 path:nth-of-type(1) {
  animation: draw 2s ease-in forwards;
  animation-delay: 0.02s;
}
#flower3 path:nth-of-type(2), #flower4 path:nth-of-type(2), #flower6 path:nth-of-type(2) {
  animation: draw 2s ease-in forwards;
  animation-delay: 0.04s;
}
#flower3 path:nth-of-type(3), #flower4 path:nth-of-type(3), #flower6 path:nth-of-type(3) {
  animation: draw 2s ease-in forwards;
  animation-delay: 0.06s;
}
#flower3 path:nth-of-type(4), #flower4 path:nth-of-type(4), #flower6 path:nth-of-type(4) {
  animation: draw 2s ease-in forwards;
  animation-delay: 0.08s;
}
#flower3 path:nth-of-type(5), #flower4 path:nth-of-type(5), #flower6 path:nth-of-type(5) {
  animation: draw 2s ease-in forwards;
  animation-delay: 0.1s;
}
#flower3 path:nth-of-type(6), #flower4 path:nth-of-type(6), #flower6 path:nth-of-type(6) {
  animation: draw 2s ease-in forwards;
  animation-delay: 0.12s;
}
#flower3 path:nth-of-type(7), #flower4 path:nth-of-type(7), #flower6 path:nth-of-type(7) {
  animation: draw 2s ease-in forwards;
  animation-delay: 0.14s;
}
#flower3 path:nth-of-type(8), #flower4 path:nth-of-type(8), #flower6 path:nth-of-type(8) {
  animation: draw 2s ease-in forwards;
  animation-delay: 0.16s;
}
#flower3 path:nth-of-type(9), #flower4 path:nth-of-type(9), #flower6 path:nth-of-type(9) {
  animation: draw 2s ease-in forwards;
  animation-delay: 0.18s;
}

#stem1 {
  stroke-dasharray: 341;
  stroke-dashoffset: -341;
}

#stem2--top {
  stroke-dasharray: 87;
  stroke-dashoffset: 87;
}

#stem2--bottom {
  stroke-dasharray: 298;
  stroke-dashoffset: 298;
}

#stem3--top {
  stroke-dasharray: 90;
  stroke-dashoffset: 90;
}

#stem3--bottom {
  stroke-dasharray: 253;
  stroke-dashoffset: 253;
}

#stem4--top {
  stroke-dasharray: 181;
  stroke-dashoffset: 181;
}

#stem4--bottom {
  stroke-dasharray: 161;
  stroke-dashoffset: 161;
}

#stem5--top {
  stroke-dasharray: 34;
  stroke-dashoffset: 34;
}

#stem5--bottom {
  stroke-dasharray: 186;
  stroke-dashoffset: 186;
}

#stem6 {
  stroke-dasharray: 270;
  stroke-dashoffset: 270;
}

#stem1, #stem6 {
  animation: draw .75s ease-in forwards;
  animation-delay: 1.25s;
}

#stem2--bottom, #stem3--bottom, #stem4--bottom, #stem5--bottom {
  animation: draw .5s ease-in forwards;
  animation-delay: 1.5s;
}

#stem2--top, #stem3--top, #stem4--top, #stem5--top {
  animation: draw .5s ease-in forwards;
  animation-delay: 1.25s;
}

@keyframes draw {
  to {
    stroke-dashoffset: 0;
  }
}
svg {
  display: block;
  margin: 2rem auto 0 auto;
  width: 20rem;
}

  </style>
 </head>
 <body>
 <svg viewBox="0 0 518 744">
  <path id="stem6" fill="none" stroke="#82C384" stroke-width="3" stroke-miterlimit="10" d="M325.3 500.8l-73.1 237.3" stroke-linecap="round"/>
  <g id="stem5" fill="none" stroke="#82C384" stroke-width="3" stroke-miterlimit="10" stroke-linecap="round">
    <path id="stem5--top" d="M420.4 329.6l-12.8 30.6"/>
    <path id="stem5--bottom" d="M334.4 533.9l-71.8 170.6"/>
  </g>
  <g id="stem4" fill="none" stroke="#82C384" stroke-width="3" stroke-miterlimit="10" stroke-linecap="round">
    <path id="stem4--top" d="M394.3 154.9l-44.6 174.7"/>
    <path id="stem4--bottom" d="M295.4 528.1l-41.2 155.3"/>
  </g>
  <g id="stem3" fill="none" stroke="#82C384" stroke-width="3" stroke-miterlimit="10" stroke-linecap="round">
    <path id="stem3--top" d="M272.7 290l-4.2 89.2"/>
    <path id="stem3--bottom" d="M263.7 480.7l-11.8 252"/>
  </g>
  <g id="stem2" fill="none" stroke="#82C384" stroke-width="3" stroke-miterlimit="10" stroke-linecap="round">
    <path id="stem2--top" d="M130.8 198.8l22.3 83.5"/>
    <path id="stem2--bottom" d="M181.2 394.7l73 288.7"/>
  </g>
  <path id="stem1" fill="none" stroke="#82C384" stroke-width="3" stroke-miterlimit="10" d="M252.2 738.3L149.8 413.7" stroke-linecap="round"/> 
  
  <g id="flower6" fill="none" stroke="#f425c3" stroke-width="3" stroke-miterlimit="10" stroke-linecap="round">
    <path d="M380 363.5c-4 17.4-25 62.1-37.6 59.2-12.6-2.9-12.1-52.3-8.1-69.7s17.4-29.1 30-26.2 19.6 19.3 15.7 36.7z"/>
    <path d="M325.4 354.1c8.1 15.9 20.8 63.6 9.3 69.5-11.5 5.9-42.9-32.3-51-48.2-8.1-15.9-5.4-33.5 6.2-39.4 11.4-5.9 27.4 2.2 35.5 18.1z"/>
    <path d="M277.5 382c16.4 6.9 56.9 35.4 51.8 47.3s-53.6 2.8-70-4.1-25.6-22.2-20.6-34.2c5-11.9 22.4-16 38.8-9z"/>
    <path d="M258.8 434.1c17-5.2 66.3-9.5 70.1 2.9s-39.3 36.6-56.3 41.9c-17 5.2-33.9-.5-37.7-12.9-3.8-12.4 6.9-26.7 23.9-31.9z"/>
    <path d="M278 486c9.7-15 44.7-49.8 55.6-42.8s-6.5 53.3-16.2 68.3-26.3 21.4-37.2 14.4c-10.9-7.1-11.9-24.9-2.2-39.9z"/>
    <path d="M326 513.5c-2.2-17.7 2.2-66.9 15-68.5s29.3 45 31.5 62.7-6.4 33.3-19.3 34.9-24.9-11.4-27.2-29.1z"/>
    <path d="M380.5 503.7c-13.1-12.1-41.3-52.7-32.5-62.2 8.8-9.5 51.4 15.7 64.4 27.8 13.1 12.1 16.5 29.6 7.7 39.1-8.8 9.6-26.5 7.4-39.6-4.7z"/>
    <path d="M416 461.1c-17.8-.9-65.5-13.8-64.9-26.7s49.4-21 67.2-20.1c17.8.9 31.7 12.1 31 25S433.8 462 416 461.1z"/>
    <path d="M415.8 405.7c-14.2 10.8-59.1 31.6-66.9 21.2-7.8-10.3 24.4-47.9 38.6-58.6 14.2-10.8 32.1-11.1 39.9-.8s2.6 27.5-11.6 38.2z"/>
  </g>
  <g id="flower5" fill="none" stroke="#aa2970" stroke-width="3" stroke-miterlimit="10" stroke-linecap="round">
    <path d="M458.7 224.3c-.8 11.4-9.5 41.7-17.8 41.2s-12.9-31.8-12.1-43.2 8.1-20.1 16.3-19.6c8.3.6 14.3 10.3 13.6 21.6z"/>
    <path d="M431.1 221.8c5 10.2 12.6 40.9 5.2 44.5-7.4 3.7-27.1-21.1-32.1-31.3s-3.1-21.5 4.4-25.1c7.4-3.6 17.5 1.7 22.5 11.9z"/>
    <path d="M406 233.4c9.5 6.3 31.4 29.1 26.8 36s-34-4.7-43.4-11.1-13.4-17-8.8-23.9 16-7.4 25.4-1z"/>
    <path d="M390.1 256c11.4.8 41.7 9.5 41.2 17.8-.6 8.3-31.8 12.9-43.2 12.1s-20.1-8.1-19.6-16.3c.6-8.3 10.2-14.4 21.6-13.6z"/>
    <path d="M387.6 283.5c10.2-5 40.9-12.6 44.5-5.2s-21.1 27.1-31.3 32.1-21.5 3.1-25.1-4.4c-3.7-7.4 1.6-17.5 11.9-22.5z"/>
    <path d="M399.1 308.6c6.3-9.5 29.1-31.4 36-26.8s-4.7 34-11.1 43.4c-6.3 9.5-17 13.4-23.9 8.8s-7.3-15.9-1-25.4z"/>
    <path d="M421.7 324.6c.8-11.4 9.5-41.7 17.8-41.2s12.9 31.8 12.1 43.2c-.8 11.4-8.1 20.1-16.3 19.6-8.3-.6-14.3-10.3-13.6-21.6z"/>
    <path d="M449.2 327.1c-5-10.2-12.6-40.9-5.2-44.5s27.1 21.1 32.1 31.3 3.1 21.5-4.4 25.1c-7.3 3.6-17.4-1.7-22.5-11.9z"/>
    <path d="M474.4 315.5c-9.5-6.3-31.4-29.1-26.8-36s34 4.7 43.4 11.1c9.5 6.3 13.4 17 8.8 23.9-4.6 6.9-16 7.3-25.4 1z"/>
    <path d="M490.3 292.9c-11.4-.8-41.7-9.5-41.2-17.8.6-8.3 31.8-12.9 43.2-12.1 11.4.8 20.1 8.1 19.6 16.3-.6 8.3-10.2 14.4-21.6 13.6z"/>
    <path d="M492.8 265.4c-10.2 5-40.9 12.6-44.5 5.2-3.7-7.4 21.1-27.1 31.3-32.1s21.5-3.1 25.1 4.4c3.7 7.4-1.6 17.5-11.9 22.5z"/>
    <path d="M481.3 240.3c-6.3 9.5-29.1 31.4-36 26.8s4.7-34 11.1-43.4c6.3-9.5 17-13.4 23.9-8.8s7.3 15.9 1 25.4z"/>
  </g>
  <g id="flower4" fill="none" stroke="#af4ef4" stroke-width="3" stroke-miterlimit="10" stroke-linecap="round">
    <path d="M357.3 50.9C371.1 57 405 82 400.5 92.1s-45.7 1.4-59.6-4.8c-13.8-6.2-21.4-19.4-16.9-29.4s19.4-13.2 33.3-7z"/>
    <path d="M340.4 94.9c14.6-4.2 56.6-6.8 59.6 3.8s-34.1 30.5-48.7 34.6c-14.6 4.2-28.9-1.1-31.9-11.7s6.4-22.6 21-26.7z"/>
    <path d="M355.7 139.5c8.5-12.6 39-41.6 48.1-35.4 9.1 6.2-6.5 45.3-15 57.8-8.5 12.6-22.8 17.7-31.9 11.6-9.2-6.3-9.7-21.5-1.2-34z"/>
    <path d="M396.1 163.8c-1.6-15.1 3.1-56.9 14.1-58.1s24.1 38.9 25.6 54c1.6 15.1-6.1 28.2-17 29.4s-21.1-10.2-22.7-25.3z"/>
    <path d="M442.7 156.4c-10.9-10.6-34.2-45.6-26.5-53.5 7.7-7.9 43.4 14.3 54.3 24.8s13.5 25.5 5.8 33.5c-7.6 7.9-22.7 5.8-33.6-4.8z"/>
    <path d="M473.7 120.8c-15.1-1.1-55.5-12.9-54.7-23.9s42.5-17 57.6-15.9 26.8 10.9 26 21.9-13.8 19-28.9 17.9z"/>
    <path d="M474.5 73.6c-12.3 8.9-50.9 25.8-57.3 16.8s21.6-40.3 33.9-49.2c12.3-8.9 27.5-8.9 34 .1s1.7 23.4-10.6 32.3z"/>
    <path d="M444.8 37c-3.7 14.7-22.4 52.4-33.1 49.8s-9.3-44.8-5.6-59.5 15.4-24.5 26.1-21.8 16.3 16.8 12.6 31.5z"/>
    <path d="M398.5 28c6.6 13.6 16.6 54.6 6.6 59.4-9.9 4.8-35.9-28.3-42.6-41.9s-4-28.6 6-33.4c10-4.9 23.4 2.2 30 15.9z"/>
  </g>
  <g id="flower3" fill="none" stroke="#aa2970" stroke-width="3" stroke-miterlimit="10" stroke-linecap="round">
    <path d="M290.7 176.1c0 13.6-8 50.6-17.9 50.6s-17.9-37-17.9-50.6 8-24.7 17.9-24.7 17.9 11 17.9 24.7z"/>
    <path d="M248.3 178.4c8.8 10.4 26.4 43.9 18.8 50.3s-37.5-16.8-46.3-27.2-9.7-24.1-2.1-30.4c7.6-6.5 20.9-3.2 29.6 7.3z"/>
    <path d="M217.4 207.3c13.4 2.4 48.4 16.7 46.7 26.5s-39.5 11.2-53 8.9c-13.4-2.4-22.9-12.2-21.2-22 1.8-9.8 14.1-15.8 27.5-13.4z"/>
    <path d="M212.3 249.4c11.8-6.8 47.8-18.3 52.8-9.8s-23 34-34.9 40.8c-11.8 6.8-25.4 5.4-30.4-3.2-4.9-8.5.7-21 12.5-27.8z"/>
    <path d="M235.4 284.9c4.7-12.8 24.9-44.8 34.2-41.4 9.3 3.4 4.2 40.9-.4 53.7s-16 20.5-25.3 17.1-13.1-16.6-8.5-29.4z"/>
    <path d="M276 297.2c-4.7-12.8-9.8-50.3-.4-53.7 9.3-3.4 29.5 28.6 34.2 41.4 4.7 12.8.9 25.9-8.4 29.3-9.4 3.5-20.7-4.2-25.4-17z"/>
    <path d="M315 280.6c-11.8-6.8-39.8-32.3-34.9-40.8 5-8.6 41 2.9 52.8 9.8 11.8 6.8 17.4 19.3 12.4 27.9-4.9 8.5-18.5 9.9-30.3 3.1z"/>
    <path d="M334.2 242.8c-13.4 2.4-51.2.9-53-8.9-1.7-9.8 33.3-24.1 46.7-26.5 13.4-2.4 25.7 3.6 27.4 13.4 1.8 9.8-7.7 19.6-21.1 22z"/>
    <path d="M324.6 201.5c-8.8 10.4-38.7 33.6-46.3 27.2-7.6-6.4 10-39.9 18.8-50.3s22-13.7 29.6-7.4 6.6 20.1-2.1 30.5z"/>
  </g>
  <g id="flower2" fill="none" stroke="#f425c3" stroke-width="3" stroke-miterlimit="10" stroke-linecap="round">
    <path d="M123.7 50.3c.8 15.9-6.3 59.5-17.9 60.1-11.6.6-23.1-42-23.9-57.9s7.9-29.3 19.4-29.8c11.6-.7 21.6 11.7 22.4 27.6z"/>
    <path d="M85.1 51.3c8.7 13.4 24.2 54.7 14.5 61s-41-24.8-49.7-38.2-7.8-29.3 1.9-35.6 24.6-.5 33.3 12.8z"/>
    <path d="M52.1 71.5c14.2 7.2 48.3 35.2 43.1 45.5s-48-1-62.1-8.2-21.4-21.4-16.2-31.7S38 64.3 52.1 71.5z"/>
    <path d="M33.7 105.5c15.9-.8 59.5 6.3 60.1 17.9s-42 23.1-57.9 23.9S6.6 139.4 6 127.9s11.8-21.6 27.7-22.4z"/>
    <path d="M34.7 144.1c13.4-8.7 54.7-24.2 61-14.5 6.3 9.7-24.8 41-38.2 49.7-13.4 8.7-29.3 7.8-35.6-1.9-6.3-9.7-.5-24.6 12.8-33.3z"/>
    <path d="M54.9 177.1c7.2-14.2 35.2-48.3 45.5-43.1s-1 48-8.2 62.1c-7.2 14.2-21.5 21.4-31.8 16.1s-12.7-21-5.5-35.1z"/>
    <path d="M88.9 195.5c-.8-15.9 6.3-59.5 17.9-60.1 11.6-.6 23.1 42 23.9 57.9s-7.9 29.3-19.4 29.8c-11.6.7-21.6-11.7-22.4-27.6z"/>
    <path d="M127.5 194.5c-8.7-13.4-24.2-54.7-14.5-61 9.7-6.3 41 24.8 49.7 38.2s7.8 29.3-1.9 35.6c-9.7 6.3-24.6.5-33.3-12.8z"/>
    <path d="M160.5 174.3c-14.2-7.2-48.3-35.2-43.1-45.5s48 1 62.1 8.2c14.2 7.2 21.4 21.5 16.1 31.8-5.2 10.3-21 12.7-35.1 5.5z"/>
    <path d="M178.9 140.3c-15.9.8-59.5-6.3-60.1-17.9s42-23.1 57.9-23.9 29.3 7.9 29.8 19.4-11.7 21.6-27.6 22.4z"/>
    <path d="M177.9 101.7c-13.4 8.7-54.7 24.2-61 14.5s24.8-41 38.2-49.7c13.4-8.7 29.3-7.8 35.6 1.9s.5 24.6-12.8 33.3z"/>
    <path d="M157.7 68.7c-7.2 14.2-35.2 48.3-45.5 43.1s1-48 8.2-62.1 21.5-21.4 31.8-16.1 12.7 21 5.5 35.1z"/>
  </g>
  <g id="flower1" fill="none" stroke="#af4ef4" stroke-width="3" stroke-miterlimit="10" stroke-linecap="round">
    <path d="M149.8 292.1c0 12.5-7.4 46.4-16.5 46.4s-16.5-33.9-16.5-46.4 7.4-22.7 16.5-22.7 16.5 10.2 16.5 22.7z"/>
    <path d="M119.5 291.4c6.3 10.8 16.8 43.9 9 48.5-7.9 4.5-31.2-21.2-37.5-32-6.3-10.9-5-23.3 2.9-27.9 7.9-4.5 19.3.6 25.6 11.4z"/>
    <path d="M92.8 305.9c10.8 6.3 36.5 29.6 32 37.5-4.5 7.9-37.6-2.7-48.5-9s-15.9-17.7-11.4-25.6 17-9.1 27.9-2.9z"/>
    <path d="M76.9 331.9c12.5 0 46.4 7.4 46.4 16.5s-33.9 16.5-46.4 16.5-22.7-7.4-22.7-16.5 10.2-16.5 22.7-16.5z"/>
    <path d="M76.2 362.2c10.8-6.3 43.9-16.8 48.5-9s-21.2 31.2-32 37.5c-10.8 6.3-23.3 4.9-27.9-2.9s.6-19.3 11.4-25.6z"/>
    <path d="M90.7 388.9c6.3-10.8 29.6-36.5 37.5-32 7.9 4.5-2.7 37.6-9 48.5-6.3 10.8-17.7 15.9-25.6 11.4-7.8-4.6-9.1-17-2.9-27.9z"/>
    <path d="M116.7 404.8c0-12.5 7.4-46.4 16.5-46.4s16.5 33.9 16.5 46.4-7.4 22.7-16.5 22.7-16.5-10.2-16.5-22.7z"/>
    <path d="M147 405.5c-6.3-10.8-16.8-43.9-9-48.5 7.9-4.5 31.2 21.2 37.5 32 6.3 10.8 4.9 23.3-2.9 27.9-7.9 4.5-19.3-.6-25.6-11.4z"/>
    <path d="M173.7 391c-10.8-6.3-36.5-29.6-32-37.5s37.6 2.7 48.5 9 15.9 17.7 11.4 25.6-17 9.1-27.9 2.9z"/>
    <path d="M189.6 365c-12.5 0-46.4-7.4-46.4-16.5s33.9-16.5 46.4-16.5 22.7 7.4 22.7 16.5-10.2 16.5-22.7 16.5z"/>
    <path d="M190.3 334.7c-10.8 6.3-43.9 16.8-48.5 9-4.5-7.9 21.2-31.2 32-37.5 10.8-6.3 23.3-4.9 27.9 2.9s-.6 19.3-11.4 25.6z"/>
    <path d="M175.8 308c-6.3 10.8-29.6 36.5-37.5 32-7.9-4.5 2.7-37.6 9-48.5 6.3-10.8 17.7-15.9 25.6-11.4 7.8 4.6 9.1 17.1 2.9 27.9z"/>
  </g>
</svg>
 </body>
</html>
