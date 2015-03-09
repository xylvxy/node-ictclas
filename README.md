# node-ictclas
============

ICTCLAS, Chinese word segment npm packet(also for english).

Example:
```js
var ICT= require(__dirname+'/../index');
var m = ICT.init();
var rst = m.segment('你好世界');
console.log(rst);
```