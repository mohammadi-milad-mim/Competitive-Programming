#!/usr/bin/env python3

n = int(input())
a = list(map(int, input().split()))
a.sort()
x = [a[n//2]]
for i in range(1, n//2+1):
    x.append(a[n//2-i])
    if n//2+i < n:
        x.append(a[n//2+i])
print(' '.join(map(str, x)))


    
