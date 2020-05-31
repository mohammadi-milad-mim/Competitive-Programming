n = int(input())
mainList = list(map(int, input().split()))
secList = mainList.copy()
mainList.sort()
plist=[]
for i in range(n):
    print(secList.index(mainList[i])+1, end =" ")





