# coding=utf-8

# 带cookies去访问课表url，拿到html源码，交给handle模块处理，最后存储为Table.txt，不返回任何值

path = './tyx/Python/Timetable/'

def Table(cookies):
    with open(path + 'Table.txt', 'w') as table:
        for i in range(0, 7):
            table.writelines("Testing...\n")
    print()