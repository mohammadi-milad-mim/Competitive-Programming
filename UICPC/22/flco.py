import heapq
from fractions import Fraction

n = int(input())
drones = []
drones.append([-((10**9)+1),-((10**9)+1),0])
for i in range(1,n+1):
    x,v = map(int,input().split())
    drones.append([x,v,i])
drones.append([(10**9)+1,(10**9)+1,n+1])
drones.sort()

alive = [0]+[1]*n+[0]
prv=list(range(-1,n+1))
nxt=list(range(1,n+3))

heap=[]
def collide(i,j):
    (x1,v1,_)=drones[i]
    (x2,v2,_)=drones[j]
    if v1>v2:
        heapq.heappush(heap,(Fraction(x2-x1,v1-v2),i,j))
        
def kill(i,j):
    if alive[i]+alive[j]!=2: return
    alive[i],alive[j]=0,0
    nxt[prv[i]]=nxt[j]
    prv[nxt[j]]=prv[i]
    collide(prv[i],nxt[j])
    
for i in range(1,n):
    collide(i,i+1)

while heap:
    (_,i,j)=heapq.heappop(heap)
    kill(i,j)

print(sum(alive))
for i in range(1,n+1):
    if alive[i]:
        print(i,end=" ")