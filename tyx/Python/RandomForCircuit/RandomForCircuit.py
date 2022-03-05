import random

from numpy import shape
data = open('./tyx/Python/RandomForCircuit/data.txt', 'r')
l = data.readlines()
a = []
for item in l:
    item = item.strip('\n')
    a.append(item.split(' '))
for i in range(14):
    s = random.randint(1, shape(a[i])[0])
    output = []
    output.append('Chapter ' + str(i) + ': ')
    output.append(a[i][s - 1])
    rep = s
    # s = random.randint(1, shape(a[i])[0])
    while(s == rep):
        s = random.randint(1, shape(a[i])[0])
    output.append(a[i][s - 1])
    print(output)
    # print(shape(a[i]))
