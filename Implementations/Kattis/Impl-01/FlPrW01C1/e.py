t = 1
while(True):
    t = int(input())
    if t==-1:
        break
    h1 = 0
    su  = 0
    for i in range(t):
        s,h2 = map(int,input().split())
        h = h2 - h1
        h1 = h2
        su+=(h*s)
    print(su,'miles')