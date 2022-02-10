while(True):
    t = input()
    if t == '': break
    a,b = map(int,t.split())
    n = a+1
    full = n**b
    if b==1:
        print('{0:.7f}'.format(100.0))
    elif b==2:
        tem = (n*3) - 2
        print('{0:.7f}'.format((tem/full)*100.0))
    elif n==4:
        tem = n
        rem = 2
        for i in range(1,b):
            tem1 = tem*3 - rem
            rem = tem
            tem = tem1
        print(rem)
        print(tem)
        print('{0:.7f}'.format((tem/full)*100.0))
    else:
        