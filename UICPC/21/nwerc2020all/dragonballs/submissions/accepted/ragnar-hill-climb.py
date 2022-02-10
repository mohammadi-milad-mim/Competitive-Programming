#!/usr/bin/env python3
from math import sqrt, floor
from random import randint, seed
from itertools import combinations
import sys

seed(31415)

n = int(input())
L, H = 0, 10**6
def query(x, y):
    global n
    if x < L or x > H or y < L or y > H: return 3*H*H
    print(x, y, flush=True)
    d = int(input())
    if d == 0: n -= 1
    if n == 0: exit(0)
    return d

while n > 0:
    p = (randint(L, H), randint(L, H))
    d = floor(sqrt(query(*p)))
    while d > 0:
        p2 = (randint(p[0] - d, p[0]+d), randint(p[1]-d, p[1]+d))
        d2 = floor(sqrt(query(*p2)))
        if d2 < d: p, d = p2, d2
