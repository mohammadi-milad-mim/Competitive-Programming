#!/usr/bin/env python3

(n, q) = map(int, input().split())
a = list(map(int, input().split()))

for _ in range(2*n*n+1):
    m = len(a)
    v = 1e90
    for i in range((m+1)//2):
        v = min(v, a[i]+a[m-1-i])
    a.append(v)

for P in range(1, n+1):
    v = a[-1] - a[-1-P]
    for i in range(1, n*n+1):
        if a[-i] - a[-i-P] != v:
            break
    else:
        break

for _ in range(q):
    k = int(input())-1
    if k < len(a):
        ans = a[k]
    else:
        base = len(a) - P + (k-len(a)) % P
        ans = a[base] + (k-base)//P * v
    print(ans)
    
