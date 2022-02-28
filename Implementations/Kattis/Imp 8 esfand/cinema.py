n,m = map(int,input().split())
nn = n
grou = list(map(int,input().split()))
t = 0
for i in grou:
    if nn-i >=0:
        nn-=i
        t+=1
print(m-t)
