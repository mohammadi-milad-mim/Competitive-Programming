n = int(input())
if n==1:
    x = int(input())
    print(1)
else:
    li = list(map(int, input().split()))
    cList=[]
    c=0
    flag=0
    for i in range(1,n):
        if li[i-1] <= li[i] :
            c+=1
            flag=1
        else:
            cList.append(c+1)
            c=0
        if i==n-1 and li[i-1] <= li[i]:
            cList.append(c+1)

    if (flag):
        print(max(cList))
    else:
        print(1)
