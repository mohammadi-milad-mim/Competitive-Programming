#!/usr/bin/env python3
import sys

n = int(sys.argv[1])
k = (n+1)//2

col0 = 1
row0 = 1

print('%d' % n)
print('%d %d' % (1, 2))
print('%d %d' % (col0, row0))

left = n
for i in range(1,k):
    print('%d %d' % (0, i))
    left -= 1

row = row0+k
col = col0
while left > 0:
    if row > n:
        row = 1
        col += 1
    print('%d %d' % (col - col0, row - row0))
    left -= 1
    row += k

