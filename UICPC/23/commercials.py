n,p = map(int, input().split())
com = list(map(int, input().split()))
com2 = [i-p for i in com]
ma = -21
ma2 = -21
for i in range(n):
    ma = max(com2[i],ma+com2[i])
    ma2 = max(ma2,ma)
print(ma2)