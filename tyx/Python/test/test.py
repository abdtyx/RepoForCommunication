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