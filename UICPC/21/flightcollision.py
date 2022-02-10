def inrange(a,b,n):
    if a>=0 and b>=0 and a<n and b<n:
        return True
    else:
        return False
def findBack(i,alive,itms):
    t = i-1
    while(t>=0):
        indexI = itms[t][2]
        if (alive[indexI]):
            return t
        t-=1
    return -1
def findFront(i,alive,itms,n):
    t = i+1
    while(t<n):
        indexI = itms[t][2]
        if (alive[indexI]):
            return t
        t+=1
    return -1

def binary_search(arr, val, start, end):
    if start == end:
        if arr[start][0] > val:
            return start
        else:
            return start+1
    if start > end:
        return start
  
    mid = (start+end)//2
    if arr[mid][0] < val:
        return binary_search(arr, val, mid+1, end)
    elif arr[mid][0] > val:
        return binary_search(arr, val, start, mid-1)
    else:
        return mid
  
def insertion(arr,li):
    if len(li)==0:
        li.append(arr)
        return li
    if len(li)==1:
        if arr[0]>=li[0][0]:
            li.append(arr)
        else:
            li = [arr] + [li[0]]
        return li
    siz = len(li)-1
    val = arr[0]
    j = binary_search(li, val, 0, siz)
    li.insert(j,arr)
    return li
    
def collide(locI1, locI2, spdI1, spdI2):
    if spdI1==spdI2:
        return 0
    elif (spdI1-spdI2<0):
        return 0
    else:
        return (locI2-locI1)/(spdI1-spdI2)

n = int(input())
alive = [1]*n
#print(alive)
itms = []
for i in range(n):
    x,y=map(int, input().split())
    itms.append([x,y,i])

itms.sort()
#print(*itms,sep=" ")
tim=[]
#tim2=[]
for i in range(1,n):
    locI1=itms[i-1][0]
    locI2 = itms[i][0]
    spdI1 = itms[i-1][1]
    spdI2 = itms[i][1]
    delta = collide(locI1,locI2,spdI1,spdI2)
    if (delta>0):
        #print(*[delta,i-1,i],sep="   ")
        #tim2.append([delta,i-1,i])
        tim = insertion([delta,i-1,i],tim)
        #bisect.bisect_right(KeyList(tim, key=lambda x: x[0]), [delta,i-1,i])

#print(*tim,sep=" ")
cnt=0
while(len(tim)!=0):
    u = tim.pop(0)
    firD=u[1]
    secD=u[2]
    i_firD=itms[firD][2]
    i_secD=itms[secD][2]
    if (alive[i_firD] and alive[i_secD]):
        cnt+=2
        alive[i_firD] =0
        alive[i_secD] = 0
        backD = findBack(i_firD,alive,itms)
        frontD = findFront(i_secD,alive,itms,n)
    if (frontD!=-1 and backD!=-1):
            locI1=itms[backD][0]
            locI2 = itms[frontD][0]
            spdI1 = itms[backD][1]
            spdI2 = itms[frontD][1]
            delta = collide(locI1,locI2,spdI1,spdI2)
            if (delta>0):
                tim = insertion([delta,backD,frontD],tim)
print(n-cnt)
for i in range(n):
    if (alive[i]):
        print(i+1,end=" ")