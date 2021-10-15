//封装ajax请求数据展示
// var BASE_URL = 'https://org.xjtu.edu.cn/openplatform';
 

var url = window.location.href;
var BASE_URL = url.split('/'); //以“/”进行分割

if(BASE_URL[2]) {
  BASE_URL =BASE_URL[0]+'//'+BASE_URL[2]+'/openplatform';
} else {
  BASE_URL = ''; //如果url不正确就取
}

 //var BASE_URL = 'http://t100xjd.zhengtoon.com/openplatform'
 //var BASE_URL = 'http://172.31.241.67:8080'

 /*
   * AJAX针对所有的数据类型的函数
   * 
   * @param {type} sync 是否异步传输 默认是true是异步。 false就是同步传输 
   * @param {type} cache 是否开启缓存
   * @param {type} type ajax的传输类型 POST 或 GET
   * @param {type} url  是传输的目标url （注意：这个url要非常注意，如果路径不对就会导致错误  !--所以是重点--）
   * @param {type} datatype 传输数据的类型可以是 text:纯文本 | html:HTML信息包括script标签会在插入DOM时执行 | script:返回纯文本JavaScript代码 | json:json数据 | jsonp:jsonp数据格式 | xml:返回XML文档 
   * @param {type} data 是要传输的数据（注意:数据是什么格式datatype就要是对应的格式，否则传输失败）
   * @param {type} func 当ajax执行成功之后跳转到自己的函数  注意:这里只需要写上自己函数的名称即可
   * @returns {undefined}
   */
function ajax_all_Filed(sync, cache, type, url, datatype, data, func) { //封装ajax的一些常用参数  //data数据可以为空
        $.ajax({
            async: sync,
            cache: cache,
            type: type,
            url: BASE_URL+url,
            dataType: datatype,
            data: data,
            beforSend: function () {
                // 禁用按钮防止重复提交
                //$("#submit").attr({disabled: "disabled"});
            },
            error: function (data) {
                //请求失败时被调用的函数 
                //alert("传输失败:" + data);
            },
            success: function (data) {
                func(data);
            }
        });
}
/*ajax_all_Filed("true", "false", "GET", "newjson.json", "json", "",function(data){
  
})*/
function judgeTime() {
    var dateObj = new Date();
    var year = dateObj.getFullYear()
    var month = addZero(dateObj.getMonth() + 1)
    var date = dateObj.getDate()
    var arr = ['星期日', '星期一', '星期二', '星期三', '星期四', '星期五', '星期六']
    var day = arr[dateObj.getDay()]
    return year + '年' + month + '月' + date + '日  ' + day
}

function addZero(time) {
    if (parseInt(time) < 10) return '0' + time
}

function cookieData(key, value) {
    if (value !== undefined) {
        value = JSON.stringify(value)
        if (value === 'false') {
          deleteCookie(key)
        } else {
          setCookie(key, value)
        }
      } else {
        var value = getCookie(key)
        if (value) value = JSON.parse(value)
        return value
      }
}
function storageData(key, value) {
    if (value !== undefined) {
        value = JSON.stringify(value)
        if (value === 'false') {
          localStorage.removeItem(key)
        } else {
          localStorage.setItem(key, value)
        }
    } else {
        var value = localStorage.getItem(key)
        if (value) value = JSON.parse(value)
        return value
      }
}

function setCookie(key, value, expiresHours) {
    var cookieString = key + '=' + value
    if (expiresHours) {
      var date = new Date()
      date.setTime(date.getTime + expiresHours * 3600 * 1000)
      cookieString = cookieString + '; expires=' + date.toGMTString()
    }
    document.cookie = cookieString + '; path=/;'
}
function getCookie(key) {
    var name = key + '='
      var ca = document.cookie.split(';')
      for (var i = 0, len = ca.length; i < len; i++) {
        var c = ca[i]
        while (c.charAt(0) === ' ') c = c.substring(1)
        if (c.indexOf(name) !== -1) return c.substring(name.length, c.length)
      }
      return ''
}

function deleteCookie(key) {
     var date = new Date()
      date.setTime(date.getTime() - 10000)
      document.cookie = key + "=''; expires=" + date.toGMTString() + '; path=/;'
}
function clearAllCookie() {
    var keysArr = document.cookie.split(';')
      if (keysArr && keysArr.length) {
        var reg = /^\s*manage_/
        for (var i = 0, len = keysArr.length; i < len; i++) {
          var keys = keysArr[i].split('=')
          if (reg.test(keys[0])) {
            deleteCookie(keys[0])
          }
        }
      }
}

function isEmail(value) { //邮箱
    var pattern = /^[a-zA-Z0-9][a-zA-Z0-9._-]*[a-zA-Z0-9]+@[a-zA-Z0-9]+([-_][a-zA-Z0-9]+)*(\.[a-zA-Z0-9]+([-_][a-zA-Z0-9]+)?)+$/
    return pattern.test(value)
}
function isNumber(value) { //数字
    var pattern = /^\d*$/
    return pattern.test(value)
}
function isPhone(value) { //电话
    var pattern = /^1[2-9]\d{9}$/
    return pattern.test(value)
}
function isBlank(value) { //是否为空
    var pattern = /^\s+$/
    return pattern.test(value)
}
function isPassword(value) {
    var pattern = /^(?![\d]+$)(?![a-zA-Z]+$)(?![^\da-zA-Z]+$).{8,20}$/
    return pattern.test(value)
}

// 不同屏幕宽
var isMobile = false
function winWide(){
	//判断屏幕宽度
	var winWide = window.screen.width;  //获取当前屏幕分辨率
  var wideScreen = false;
  

	if(winWide <= 1024){  //1024及以下分辨率
  //这里写要加载的代码
  isMobile = true
  var width = document.documentElement.clientWidth / 10;
	document.documentElement.style.fontSize = width + 'px';
	}
	else{  //大于1024的分辨率
  //这里写要加载的代码 
  isMobile = false
	}
}
winWide()



