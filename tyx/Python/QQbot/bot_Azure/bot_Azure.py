# -*- coding: UTF-8 -*-
import urllib.request
import urllib.parse

from API.DayTableInfoAPI import GetDayTable

# bot域名
url = "http://127.0.0.1:5700"

# 卡中文解法：urllib.parse.quote("中文")
# msg = "我是一个bot"
msg = urllib.parse.quote(GetDayTable().strip('\n'))

# 群组消息API调用
group_msg = url + "/send_group_msg?group_id=913813594&message=" + msg

# 获取好友信息API调用
get_friends_info = url + "/get_friend_list"

try:
    html = urllib.request.urlopen(group_msg, timeout=5)
    print(html.read())
except Exception as result:
    print(result)
