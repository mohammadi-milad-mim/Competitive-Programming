n,v = map(int,input().split())
mx = -1
for i in range(n):
    l,w,h = map(int,input().split())
    vo = l*w*h
    #print(vo)
    if vo>mx: mx = vo
print(mx - v)