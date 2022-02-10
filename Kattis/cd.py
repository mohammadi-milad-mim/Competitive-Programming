a,b=map(int,input().split())
while(a+b != 0):
    c=0
    dp = [0]*1000000004
    for i in range(a):
        x = int(input())
        dp[x]=1
    for j in range(b):
        x=int(input())
        if dp[x]==1:
            c+=1
    print(c)
    a,b=map(int,input().split())