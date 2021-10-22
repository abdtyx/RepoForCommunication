# coding=utf-8
import requests
import json
import time


usrid = 2203612988
memberId = "840404"
auth_info = {
    "loginType" : 1,
    "username" : usrid,
    "pwd" : "bnfM91jhtYx0oY+vtFnmJw==",
    "jcaptchaCode" : ""
}




tm_wk = "5" # 周
xnxqdm = "2021-2022-1" # 学年学期
debug = False
LoginTimes = 0



def login(s):
    print("Logining...")
    r = s.get("http://ehall.xjtu.edu.cn/jwapp/sys/wdkb/*default/index.do#/wdkb", allow_redirects=False)
    url = r.headers['Location']
    if debug:
        print("Goto:" + url)
    r = s.get(url, allow_redirects=False)
    url = r.headers['Location']
    if debug:
        print("Goto:" + url)
    s.get(url)
    r = s.post("http://org.xjtu.edu.cn/openplatform/g/admin/login", json=auth_info, allow_redirects=False)
    if debug:
        print(r.text)
    logindata = json.loads(r.text)
    s.cookies.set("memberId", memberId)
    s.cookies.set("open_Platform_User", logindata['data']['tokenKey'])
    r = s.get("http://org.xjtu.edu.cn/openplatform/g/admin/getUserIdentity?memberId=" + memberId)
    if debug:
        print(r.text)
    r = s.get("http://org.xjtu.edu.cn/openplatform/oauth/auth/getRedirectUrl?userType=1&personNo=" + str(usrid), headers = {"Referer" : "http://org.xjtu.edu.cn/openplatform/login.html"})
    if debug:
        print(r.text)
    url = json.loads(r.text)['data']
    if debug:
        print("Goto:" + url)
    s.get(url)
    r = s.get("http://ehall.xjtu.edu.cn/portal/html/select_role.html?appId=4770397878132218")
    if debug:
        print(r.status_code)
    r = s.get("http://ehall.xjtu.edu.cn/jwapp/sys/wdkb/*default/index.do?amp_sec_version_=1&gid_=S3dzUjIyZ1lnbzdra0gwMk1BaWwwUkpQUHp1VlY3MHRiWDNpRW9FeU9qb2tSUDhKbStqUVlxZllYR2YxU1doRmFTdlpnVWhWUWxRamtieUxvZE1rZEE9PQ&EMAP_LANG=zh&THEME=millennium#/xskcb")
    if debug:
        print(r.status_code)






def SendMail(str):
    print(str)





with requests.Session() as s:
        login(s)
        '''
        xskcb_payload = "XNXQDM=" + xnxqdm + "&SKZC=" + tm_wk
        r = s.post("http://ehall.xjtu.edu.cn/jwapp/sys/wdkb/modules/xskcb/xskcb.do", data=xskcb_payload, allow_redirects=False)
        '''
        r = s.post("http://ehall.xjtu.edu.cn/jwapp/sys/wdkb/modules/xskcb/xskcb.do?XNXQDM=" + str(xnxqdm) + "&SKZC=" + str(tm_wk), allow_redirects=False)
        while (r.status_code != 200):
            login(s)
            '''
            r = s.post("http://ehall.xjtu.edu.cn/jwapp/sys/wdkb/modules/xskcb/xskcb.do", data=xskcb_payload, allow_redirects=False)
            '''
            r = s.post("http://ehall.xjtu.edu.cn/jwapp/sys/wdkb/modules/xskcb/xskcb.do?XNXQDM=2021-2022-1&SKZC=5", allow_redirects=False)
            LoginTimes += 1
            if (LoginTimes == 5):
                SendMail("登录失败")
        data = json.loads(r.text)
        # print(r.text)
        rstr = ""
        for item in data['datas']['xskcb']['rows']:
            rstr += str(item['KCM']) + " " + str(item['YPSJDD']) + ","
        SendMail(rstr)
        print("课表查询完毕")



