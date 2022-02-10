h,w,n = map(int,input().split())
bri = list(map(int,input().split()))
t=0
for i in range(h):
    li =0
    while(li<w):
        li+=bri[t]
        t+=1
    if li==w:
        continue
    else:
        print("NO")
        break
else:
    print("YES")
        