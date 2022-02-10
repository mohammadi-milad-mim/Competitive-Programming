n,p = map(int, input().split())
com = list(map(int, input().split()))
com2 = [i-p for i in com]
ma = -21
ma2 = -21
ii = -1
jj = n+1
for i in range(n):
    if com2[i]>ma+com2[i]:
        ma = com2[i]
        ii = i
    else:
        ma = com2[i]+ma
    if ma > ma2:
        ma2 = ma
        jj = i
print(ma2)
print(ii)
print(jj)