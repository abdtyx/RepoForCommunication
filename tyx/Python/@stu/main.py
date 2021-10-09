import requests

url = "http://10.6.18.2/cgi-bin/srun_portal?callback=jQuery112405762570163683285_1633697066964&action=login&username=2203612988%40stu&password=%7BMD5%7De012acc03127d1006f71d0ce32109609&ac_id=1&ip=10.172.24.133&chksum=f20c167a0d8f9b127c56116b2a28a980c2df5096&info=%7BSRBX1%7DM7pN2eRhvCzxDUNHwd2kUk%2BlwGToniWRutgmSg0b638WXsAQAXjgzZX0WKZOs84qGCDPZ1zEQdpOTnf%2BnTD8xA3ulL3ARobkhCESAJG57aFDsqyCje1Eaww4iB94fXVHaygGzW0tln%2ByZglnS%2FantL%3D%3D&n=200&type=1&os=Windows+10&name=Windows&double_stack=0&_=1633697066967"

headers = {
    "Accept": "text/javascript, application/javascript, application/ecmascript, application/x-ecmascript, */*; q=0.01",
    "Accept-Encoding": "gzip, deflate",
    "Accept-Language": "zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6",
    "Connection": "keep-alive",
    "Cookie": "lang=zh-CN",
    "Host": "10.6.18.2",
    "Referer": "http://10.6.18.2/srun_portal_pc?ac_id=1&mac=3897d6b4e001&nasip=10.6.16.245&ssid=&t=wireless-v2-plain&theme=basic&url=http%3A%2F%2Fedge.microsoft.com%2Fcaptiveportal%2Fgenerate_204&wlanacname=XJTU-Wlan-Auth-&wlanuserip=10.172.24.133",
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/94.0.4606.71 Safari/537.36 Edg/94.0.992.38",
    "X-Requested-With": "XMLHttpRequest"
}

data = {
    "callback": "jQuery112405762570163683285_1633697066964",
    "action": "login",
    "username": "2203612988@stu",
    "password": "{MD5}e012acc03127d1006f71d0ce32109609",
    "ac_id": 1,
    "ip": "10.172.24.133",
    "chksum": "f20c167a0d8f9b127c56116b2a28a980c2df5096",
    "info": "{SRBX1}M7pN2eRhvCzxDUNHwd2kUk+lwGToniWRutgmSg0b638WXsAQAXjgzZX0WKZOs84qGCDPZ1zEQdpOTnf+nTD8xA3ulL3ARobkhCESAJG57aFDsqyCje1Eaww4iB94fXVHaygGzW0tln+yZglnS/antL==",
    "n": 200,
    "type": 1,
    "os": "Windows 10",
    "name": "Windows",
    "double_stack": 0,
    "_": 1633697066967
}

def main():
    response = requests.post(json=data, headers=headers, url=url)
    try:
        print(response.text)
    except Exception as result:
        print(result)

if __name__ == "__main__":
    main()
'''
url = "http://10.6.18.2/srun_portal_pc?ac_id=1&srun_wait=1&theme=basic"

data = {
    "username" : "2203612988@stu",
    "password" : "2203612988"
}

def main():
    response = requests.post(url=url, data=data)
    try:
        print(response.text)
    except Exception as result:
        print(result)

if __name__ == "__main__":
    main()
'''