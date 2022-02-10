#!/usr/bin/env python3
import sys

n = int(sys.argv[1])
peak_pos = int(sys.argv[2])
ones = int(sys.argv[3])

a = [0]*n
a[0] = a[-1] = 10
a[peak_pos] = n+1
for i in range(2, n, 2):
    if ones > 0 and peak_pos+i < n:
        a[peak_pos+i] = 1
    if ones < 0 and peak_pos-i >= 0:
        a[peak_pos-i] = 1

print(len(a))
print(' '.join(map(str, a)))
