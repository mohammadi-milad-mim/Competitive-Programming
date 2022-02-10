#!/usr/bin/python3
n = int(input())
temps = sorted(map(int, input().split()))

half = n//2
res = [temps[half]]
for i in range(1, half+1):
    res.append(temps[half - i])
    if half + i < n:
        res.append(temps[half + i])
print(' '.join(map(str, res)))
