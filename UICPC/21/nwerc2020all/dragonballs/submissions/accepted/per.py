#!/usr/bin/env python3
from math import sqrt, ceil
import sys

MAX_C = 10**6
n = int(input())
empty = [[] for _ in range(MAX_C+1)]

for y in range(MAX_C+1):
    E = empty[y]
    E.sort()
    i = x = 0
    while n and x <= MAX_C:
        if i < len(E) and E[i][0] <= x:
            x = max(x, E[i][1]+1)
            i += 1
        else:
            print('%d %d' % (x, y))
            d2 = int(input())
            if not d2: n -= 1
            for dy in range(1, d2+1):
                if y+dy > MAX_C or dy*dy > d2: break
                dx = ceil(sqrt(d2 - dy*dy)) - 1
                empty[y+dy].append((x-dx, x+dx))
            x += max(1, ceil(sqrt(d2)))


