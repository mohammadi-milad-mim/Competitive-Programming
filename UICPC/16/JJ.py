for i in range (int(input())):
    n, m = map(int,input().split())
    h = []
    for j in range(m):
        h.append(int(input()))
    h.sort()
    mi = h[0]
    ma = h[-1]
    ran = ma - mi
    print(ran)
    step = ran / n
    print(step)
    ite = 0
    li = []
    for j in range(1,n+1):
        d_mi = h[ite]
        oh = j*step
        print(oh)
        while (h[ite]<oh):
            ite+=1
        d_ma=h[ite]
        mid = d_ma-d_mi/2
        li.append(mid)
        print(li)
    
    thema = max(li)
    print("{:.1f}".format(thema))
    