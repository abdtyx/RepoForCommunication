import random

with open("./tyx/cpp/Codeforces/R795Div2/a.txt", 'w') as fp:
    fp.write("1\n")
    fp.write("200000\n")
    for i in range(1, 200000):
        # fp.write(str(random.randint(-1000000000, 1000000000)) + " ")
        # a = random.randint(1, 10)
        # if (a == 10):
        #     fp.write(str(random.randint(1, 10)) + " ")
        # else:
        #     fp.write(str(random.randint(-10, 0)) + " ")
        fp.write("-1000000000" + " ")
    fp.write("\n")