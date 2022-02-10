for i in range(int(input())):
    s=""
    n = int(input())-2
    lis = list(input().split())
    s+=lis[0][0]
    back = lis[0][1]
    flag = True
    for i in range(1,n):
        forw = lis[i][0]
        if not(back==forw):
            flag=False
            s+=back
            s+=forw
        else: 
            s+=forw
        back=lis[i][1]
    s+=back
    if (flag):
        s+='a'
    print(s)