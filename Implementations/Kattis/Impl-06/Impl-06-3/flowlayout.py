n = int(input())
while (n):
    mxd = 0
    cud = 0
    mxw = 0
    tw = n
    a,b = map(int,input().split())
    while(a+b!=-2):
        if (tw-a<0):
            tw=n
            cud+=mxd
        if b+cud > mxd: 
            mxd=b+cud
        tw-=a
        if n-tw>mxw:
            mxw=n-tw
        a,b = map(int,input().split())
    print(mxw,'x',mxd)
    n = int(input())