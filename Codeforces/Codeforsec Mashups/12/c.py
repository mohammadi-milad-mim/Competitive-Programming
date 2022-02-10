n = int(input())
li = list(map(int,input().split()))
ev=0
od=0
su = 0
for i in li:
    if i%2:
        od+=1
    else:
        ev+=1

if od%2:
    print(od)
else:
    print(ev)
     