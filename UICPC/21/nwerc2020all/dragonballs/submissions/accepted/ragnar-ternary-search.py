#!/usr/bin/env python3
from math import sqrt
from random import randint, seed
from itertools import combinations

seed(31415)

# Pick n+1 distinct random points. At least two of them will be in the same Voronoi cell.

n = int(input())
L, H = 0, 10**6
def query(x, y):
    global n
    if x < L or x > H or y < L or y > H: return -1
    print(x, y, flush=True)
    d = int(input())
    if d == 0: n -= 1
    if n == 0: exit(0)
    return d

while n > 0:
    l, h = L, H
    while l < h:
        m1 = (l+l+h)//3
        m2 = (l+h+h+1)//3
        d1 = query(m1, 0)
        d2 = query(m2, 0)
        if d1 > d2: l = m1 + 1
        else: h = m2 - 1

    d = query(l, 0)
    query(l, round(sqrt(d)))
