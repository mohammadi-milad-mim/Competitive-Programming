#!/usr/bin/env python3
from math import sqrt
from random import seed, randint
seed(31415)
n = int(input())
L, H = 0, 10**6
qs = 0
def query(x, y):
    global n, qs
    qs += 1
    print(x, y, flush=True)
    d = int(input())
    if d == 0: n -= 1
    return d

while n > 0:
    x = randint(L, H-1)

    d1 = query(x, 0)
    if d1 == 0: continue

    d2 = query(x+1, 0)
    if d2 == 0: continue

    if (d1-d2+1)%2!=0: continue
    dx = (d1-d2+1)//2
    y = round(sqrt(d1-dx*dx))
    if n == 1:
        while qs <= 999:
            query(0,0)
    query(x+dx, y)

print(' \n\t\n')
