from bs4 import BeautifulSoup
import re
import urllib.request
import sys
import sqlite3

def main():
    # 目标网址
    baseurl = "http://ehall.xjtu.edu.cn/jwapp/sys/wdkb/*default/index.do?amp_sec_version_=1&gid_=S3dzUjIyZ1lnbzdra0gwMk1BaWwwUkpQUHp1VlY3MHRiWDNpRW9FeU9qb2tSUDhKbStqUVlxZllYR2YxU1doRmFTdlpnVWhWUWxRamtieUxvZE1rZEE9PQ&EMAP_LANG=zh&THEME=millennium#/xskcb"
    # baseurl = "http://org.xjtu.edu.cn/openplatform/login.html" # 测试登录
    # 测试网址
    # baseurl = "http://httpbin.org/post"
    # 测试
    # response = askUrl(baseurl)
    # datalist = getData(baseurl)
    # print(datalist[0])
    response = getData(baseurl)
    print(response)
    '''
    try:
        print(response.read().decode('utf-8'))
    except Exception as result:
        print("无法读取，错误如下：")
        print(result)
    '''
    # saveData(savepath)
    # savepath = ".\\课表.xlsx"   #保存路径


# 请求网址
def askUrl(baseurl):
    '''
    # 默认get模式
    # 初始化response应为html对象
    # response = urllib.request.urlopen("")   # 初始化response
    response = ""
    try:    # 捕获异常码
        response = urllib.request.urlopen(baseurl, timeout=10)
        # 状态码捕获暂未完成
        # print(response.status)
    except Exception as result:
        print("打开失败")
        print(result)
    finally:
        return response
    '''
    # post模式
    # response = urllib.request.urlopen("https://httpbin.org")
    try:
        headers = {
            "Cookie": "route=4e1029b6d2fd71bcfc9aea3454a71763; cur_appId_=GRt5IN2Ni3M=; state=xjdCas; JSESSIONID=0827108EAD8C1D3FA24FA7C345160A9A; sid_code=workbench_login_jcaptcha_0827108EAD8C1D3FA24FA7C345160A9A",
            "User-Agent" : "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/93.0.4577.63 Safari/537.36 Edg/93.0.961.47",
        }
        data = {
            "loginType": 1,
            "username": "2203612988",
            "pwd": "bnfM91jhtYx0oY+vtFnmJw==",
            "jcaptchaCode": ""
        }
        # data = bytes(urllib.parse.urlencode({'name' : 'user_name'}), encoding="utf-8")
        req = urllib.request.Request(url=baseurl, headers=headers, data=data, method="POST")
        response = urllib.request.urlopen(req)
        # 打印返回页面
        print(response.read().decode("utf-8"))
    except Exception as result:
        if hasattr(result, "code"):
            print("错误代码：", result.code, sep="")
            # print("错误代码：%d" % result.code)
        if hasattr(result, "reason"):
            print(result.reason)
        # print("打开失败")
        # print(result)
    finally:
        return response


# 获取数据
def getData(baseurl):
    datalist = []
    # MAX = 10
    # for i in range(0, MAX)
    # 循环体
    response = askUrl(baseurl)
    html = response.read().decode('utf-8')
    # datalist.append(html)
    return html



# 保存数据
def saveData(savepath):
    print("save...")



# 程序入口
if __name__ == "__main__":
    main()