for i in range(int(input())):
    n,s,a = map(int,input().split())
    t = (n-1)*a + s
    if t%n:
        print(-1)
    else:
        t2 = t//n
        res = t2-a
        if res>0:
            print(res)
        else:
            print(-1)