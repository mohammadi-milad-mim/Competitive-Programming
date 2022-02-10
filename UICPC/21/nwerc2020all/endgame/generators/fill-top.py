#!/usr/bin/env python3
import sys

n = int(sys.argv[1])
k = (n+1)//2

col0 = 1
row0 = n

print('%d' % n)
print('%d %d' % (2, n))
print('%d %d' % (col0, row0))

left = n
for i in range(1,k):
    print('%d %d' % (i, 0))
    left -= 1

row = row0
col = col0+k
while left > 0:
    if col > n:
        col = 1
        row -= 1
    print('%d %d' % (col - col0, row - row0))
    left -= 1
    col += k

