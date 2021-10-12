# coding=utf-8

from os import read
import time
from Login import LoginEhall
from GetTable import Table
from GetChangeInfo import Change

# 该API不需要任何参数，返回日课表（列表类型）

def GetDayTable():
    # 账号信息，密码需用加密过的
    userinfo = {}
    # netid = ""
    # password = ""
    # 选择新用户还是老用户登录，只能保存一个账号
    flag = input("是否使用原账号？(y or n)")
    if (flag == "Y" or flag == "y"):
        with open('userinfo.txt', 'r') as readuserinfo:
            userinfo["netid"] = readuserinfo.readline()
            userinfo["password"] = readuserinfo.readline()
    else:
        userinfo["netid"] = input("请输入新的账号")
        userinfo["password"] = input("请输入ehall加密的密码")
        with open('userinfo.txt', 'w') as changeuserinfo:
            changeuserinfo.writelines(userinfo["netid"])
            changeuserinfo.writelines(userinfo["password"])
    # userinfo = {
    #     "netid" : netid,
    #     "password" : password
    # }
    # Login模块处理登录ehall
    cookies = {}
    # 获得LoginEhall返回的保持在线的cookies，用该cookies访问课表html
    cookies = LoginEhall(userinfo)
    # 检测时间，存储到文件，每周一更新一次文件中的日期，可识别是否到新的一周
    localtime = time.localtime(time.time())
    # 周课表全局变量，类型：列表
    # 周课表应为二级列表，0-6表示wday，每一个元素是当日课表的列表
    weektable = []
    # 若周一，则localtime.tm_wday == 0
    # 因为要处理time.txt，若此前不存在time.txt，将会报错，因此先初始化一个time.txt并且写入三行“-1”
    try:
        trytime = open('time.txt', 'r')
    except Exception as result:
        print("第一次运行，正在初始化time.txt")
        trytime = open('time.txt', 'w')
        trytime.writelines("-1")
        trytime.writelines("-1")
        trytime.writelines("-1")
        print("初始化time.txt完成")
    finally:
        trytime.close()
    if (localtime.tm_wday == 0):
        # 若为周一，需要判断该周是否已获取了课表，若已获取，不fetch新课表
        with open('time.txt', 'r') as timer1:
            tm = timer1.readlines()
            if (tm[0] == str(localtime.tm_year) and tm[1] == str(localtime.tm_yday)):
                # 同一周周一，不改时间，不获取新列表，直接拿取Table.txt的数据
                with open('Table.txt', 'r') as tb1:
                    weektable = tb1.readlines()
            else:
                # 新一周，因此更改时间，表示新的当前周
                with open('time.txt', 'w') as changetime:
                    changetime.writelines(localtime.tm_year)
                    changetime.writelines(localtime.tm_yday)
                    changetime.writelines("-1")
                # 调用GetTable抓取新课表，之后可在Table.txt获取课表信息
                Table()
                with open('Table.txt', 'r') as tb2:
                    weektable = tb2.readlines()
    else:
        # 若不为周一，必获取新课表
        with open('Table.txt', 'r') as tb3:
            weektable = tb3.readlines()
    # 课表获取完毕，接下来获取调课信息
    with open('time.txt', 'r') as timer2:
        tm = timer2.readlines()
        if (tm[-1] != str(localtime.tm_wday)):
            # 今天没有获取调课信息
            # 覆写日期
            tm[-1] = str(localtime.tm_wday)
            with open('time.txt', 'w') as wr:
                for date in tm :
                    wr.writelines(date)
            # 调用Change()调整课表
            Change()
            # 将weektable重赋值为新的课表信息
            with open('Table.txt', 'r') as ChangedTable:
                weektable = ChangedTable.readlines()
    return weektable[localtime.tm_wday]