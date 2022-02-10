n,p = map(int, input().split())
com = list(map(int, input().split()))
com2 = [i-p for i in com]
dp = [-21 for ii in range(n)]
s=0
ma = -21
pai = [-1,-1]
for i in range(n):
    s+=com2[i]
    if s >ma:
        ma = s
        pai = i
    dp[i]=s
for i in range(1,n):
    di = com2[i-1]
    for j in range(i,n):
        te = dp[j]-di
        if te>ma:
            ma=te
            pai = j
        dp[j]= te
print(ma)