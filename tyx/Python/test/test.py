'''
import requests
import json
baseurl = "http://org.xjtu.edu.cn/openplatform/g/admin/login"
# baseurl = "http://ehall.xjtu.edu.cn/jwapp/sys/wdkb/*default/index.do?amp_sec_version_=1&gid_=S3dzUjIyZ1lnbzdra0gwMk1BaWwwUkpQUHp1VlY3MHRiWDNpRW9FeU9qb2tSUDhKbStqUVlxZllYR2YxU1doRmFTdlpnVWhWUWxRamtieUxvZE1rZEE9PQ&EMAP_LANG=zh&THEME=millennium#/xskcb"
headers = {
    # "Accept": "*/*",
    # "Accept-Encoding": "gzip, deflate",
    # "Accept-Language": "zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6",
    # "Connection": "keep-alive",
    # "Content-Length": 90,
    # "Content-Type": "application/json;charset=UTF-8",
    "Cookie": "route=4e1029b6d2fd71bcfc9aea3454a71763; cur_appId_=GRt5IN2Ni3M=; state=xjdCas; JSESSIONID=0827108EAD8C1D3FA24FA7C345160A9A; sid_code=workbench_login_jcaptcha_0827108EAD8C1D3FA24FA7C345160A9A",
    "User-Agent" : "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/94.0.4606.61 Safari/537.36 Edg/94.0.992.31",
    "Host": "org.xjtu.edu.cn",
    "Origin": "http://org.xjtu.cn",
    "Referer": "http://org.xjtu.edu.cn/openplatform/login.html"
}
data = {
    "username": "2203612988",
    "pwd": "bnfM91jhtYx0oY+vtFnmJw==",
    "loginType": 1,
    "jcaptchaCode": ""
}
s = requests.Session()
response = s.post(url=baseurl,json=data,headers=headers)
print(response.text)
'''
import urllib.request
import urllib.parse
# url = "http://ehall.xjtu.edu.cn/jwapp/sys/frReport2/show.do?reportlet=wdkb/timeTableForStu10.cpt&XH=2203612988&XNXQDM=2021-2022-1&QUERYID=29160a9b0fac46cdb894ebd8d7fa7873"
url = "http://ehall.xjtu.edu.cn/jwapp/sys/wdkb/*default/index.do?amp_sec_version_=1&gid_=S3dzUjIyZ1lnbzdra0gwMk1BaWwwUkpQUHp1VlY3MHRiWDNpRW9FeU9qb2tSUDhKbStqUVlxZllYR2YxU1doRmFTdlpnVWhWUWxRamtieUxvZE1rZEE9PQ&EMAP_LANG=zh&THEME=millennium#/xskcb"
# url = "http://ehall.xjtu.edu.cn/jsonp/sendRecUseApp.json?appId=4770397878132218&_=1632736437084"
headers = {
    "Accept": "application/json, text/javascript, */*; q=0.01",
    "Accept-Encoding": "gzip, deflate",
    "Accept-Language": "zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6",
    "Connection": "keep-alive",
    "Cookie": "CASTGC=nGH6JqHtGUVEjBMwWE5hFaPUhv33KvHXCF5LzbJHGUA8593qodRv7A==; MOD_AMP_AUTH=MOD_AMP_a8351848-c460-49b4-a961-ad1bd413032c; route=8b9256afce303b2bfefa79284f0e767c; asessionid=1b34fe73-6bc6-4fb5-862c-6de58b061208; amp.locale=undefined; JSESSIONID=l6YmrTrdLatC-j8ZllR9qOLTVDkuH12v_Rc_Mj9KQan94o94HxJP!-564554621",
    "Host": "ehall.xjtu.edu.cn",
    "Referer": "http://ehall.xjtu.edu.cn/new/index.html?browser=no",
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/94.0.4606.61 Safari/537.36 Edg/94.0.992.31",
    "X-Requested-With": "XMLHttpRequest"
}
req = urllib.request.Request(headers=headers, url=url)
response = urllib.request.urlopen(req)
print(response.read().decode("utf-8"))