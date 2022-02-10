#!/usr/bin/env python3
from math import sqrt
n = int(input())
L, H = 0, 10**6
def query(x, y):
    global n
    print(x, y, flush=True)
    d = int(input())
    if d == 0: n -= 1
    return d

while n > 0:
    d1 = query(0, 0)
    if d1 == 0: continue

    d2 = query(1, 0)
    if d2 == 0: continue

    if d2 >= d1:
        s = int(sqrt(d1))
        assert d1 == s*s
        assert query(0, s) == 0
        continue

    assert (d1-d2+1)%2==0
    x = (d1-d2+1)//2
    y = int(sqrt(d1-x*x))
    assert x*x+y*y==d1
    assert query(x, y) == 0
