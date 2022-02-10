for i in range(int(input())):
    temp = []
    n,a,b = map(int,input().split())
    if (a<b):
        h = n//2
        lh = n - b + 1
        rh = a
        if (lh<=h and rh<=h):
            for i in range(n,b,-1):
                temp.append(i)
            temp.append(a)
            for i in range(a+1,b):
                temp.append(i)
            temp.append(b)
            for i in range(a-1,0,-1):
                temp.append(i)
            print(*temp,sep=' ')
        else:
            print(-1)
    else:
        h = n//2
        if (a==h+1 and b==h):
            for i in range(n,0,-1):
                temp.append(i)
            print(*temp,sep=' ')
        else:
            print(-1)