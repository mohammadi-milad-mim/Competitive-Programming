li = []
nli = []
n = int(input())
for i in range(n):
    li.append(input())
    nli.append([i])
a=0
#print(nli)
for i in range(n-1):
    a,b = map(int,input().split())
    a-=1
    b-=1
    nli[a]+=nli[b]
    nli[b] = []
res = ""
for i in range(n):
    print(li[nli[a][i]],sep='',end='')