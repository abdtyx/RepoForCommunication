answer = {1 : "(1) 自己画\n(2) 1/3; 1/2; 5/6", 2 : "F(x)=x^2/R^2", 5 : "(1) 1/e\n(2) 1", 6 : "x\t-1\t0\t0.5\t1\nP\t0.125\t0.5\t0.25\t0.125", 8 : "(1) x ~ H(5,3,15)\n(2) x ~ B(5,0.2)"}
'''
懒人福利
for ans in answer.items():
    print(ans)
'''
a = 998244353
a = int(input("查询请输入题号，退出请输入0: "))
while(a != 0):
    try:
        print(answer[a])
    except Exception as result:
        print("本次作业没有该题")
    finally:
        a = int(input("查询请输入题号，退出请输入0："))