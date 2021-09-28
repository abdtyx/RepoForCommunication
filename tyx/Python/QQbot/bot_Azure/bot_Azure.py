# -*- coding: UTF-8 -*-
import urllib.request
import urllib.parse
# msg = "我是一个bot"
# 卡中文解法：urllib.parse.quote("中文")
msg = urllib.parse.quote("Azure在这一天学会了中文")
url = "http://127.0.0.1:5700/send_group_msg?group_id=913813594&message=" + msg
try:
    html = urllib.request.urlopen(url, timeout=5)
    print(html.read())
except Exception as result:
    print(result)
