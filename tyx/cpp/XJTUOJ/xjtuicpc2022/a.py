from asyncore import write
import random

with open('E:\\cpp\git_repository\\RepoForCommunication\\tyx\\cpp\\XJTUOJ\\xjtuicpc2022\\a.txt', 'w') as fp:
    fp.write('1000000\n')
    for i in range(1000000):
        fp.write(str(random.randint(1, 1000000000)) + ' ')