#!/usr/bin/env python3
n,r,m = [int(i) for i in input().split()]
data = [input().split() for i in range(m)]
data = [(int(t), float(p), int(d)) for t,p,d in data]

inf = n*50000
lower,upper = 0, inf
while upper-lower > 10**-7:
    mid = (lower+upper)/2
    DP = [0]*(r-n) # i-th iteration of DP[j] := Expected extra time it takes to break the record compared to an optimal run just before attempting trick m-i with j margin for error remaining. 
    for t,p,d in reversed(data):
        DP = [p * DP[j] + (1-p) * min(mid + t, inf if j<=d else d+DP[j-d]) for j in range(r-n)]
    if DP[r-n-1] > mid: lower = mid
    else:               upper = mid
print(n + (lower+upper)/2)

