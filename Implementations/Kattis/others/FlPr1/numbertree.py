li=list(input().split())
le=int(li[0])
root = (2**(le+1))-1
if len(li)==1:
    print(root)
else:
    pa = list(li[1])
    n = len(pa)
    nn = n-1
    c=0
    te = root
    for ii in range(1,n):
        te-=(2**(ii))
    for t in range(nn):
        if pa[t]=='R':
            c-=2**(nn-t)
    if pa[nn]=='R':
        c-=2
    else:
        c-=1
    print(te+c)