# -*- coding: UTF-8 -*-
import urllib.request

# msg = "我是一个bot"

try:
    html = urllib.request.urlopen("http://127.0.0.1:5700/send_group_msg?group_id=913813594&message=I'm%20not%20a%20bot", timeout=5)
    print(html.read())
except Exception as result:
    print(result)
