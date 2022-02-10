import sys

s,n,m = map(int,input().split())
li = []
for line in sys.stdin:
    tem = list(map(int, line.split()))
    li.extend(tem)

#print(li)
j = 0
start = True
state = True
res = []
i =0
while(i!=s-1):
    if li[i]<li[i+1]:
        if i==0:
            start=True
        if state:
            j+=1
            i+=1
            if i==s-1:
                res.append(j+1)
                break
        
        else:
            res.append(j+1)
            j=0
            state = True
    else:
        if i==0:
            start=False
            state = False
        
        if state:
            res.append(j+1)
            j=0
            state = False
        
        else:
            j+=1
            i+=1
            if i==s-1:
                res.append(j+1)
                break
#print(res)

le = len(res)
c1=0
c2=0
if start:
    for i in range(le-1):
        if not(i%2):
            if res[i]>=n and res[i+1]>=n:
                c1+=1
        else:
             if res[i]>=m and res[i+1]>=m:
                 c2+=1
else:
    for i in range(le-1):
        if (i%2):
            if res[i]>=n and res[i+1]>=n:
                c1+=1
        else:
             if res[i]>=m and res[i+1]>=m:
                 c2+=1

print(c1,c2)
    