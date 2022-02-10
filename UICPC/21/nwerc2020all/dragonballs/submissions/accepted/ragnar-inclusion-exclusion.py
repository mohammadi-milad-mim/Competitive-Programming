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

# Circle-Circle intersection. Rounds all intersections to integers.
def intersect(p1, d1, p2, d2):
    x = p1[0] - p2[0]
    y = p1[1] - p2[1]
    r1 = sqrt(d1)
    r2 = sqrt(d2)
    n = x*x+y*y
    D = -(n - (r1+r2)*(r1+r2))*(n - (r1-r2)*(r1-r2))
    if D < 0: return []
    xmid = x*(-r1*r1+r2*r2+n)
    ymid = y*(-r1*r1+r2*r2+n)

    def rnd(x, y): return (round(x), round(y))

    if D==0: return [rnd(p2[0] + xmid/(2*n),p2[1] + ymid/(2*n))]
    sd = sqrt(D)
    return [rnd(p2[0] + (xmid - y*sd)/(2*n), p2[1] + (ymid + x*sd)/(2*n)),
            rnd(p2[0] + (xmid + y*sd)/(2*n), p2[1] + (ymid - x*sd)/(2*n))]

while n > 0:
    ps = set()
    while len(ps) < n+1:
        ps.add((randint(L, H), randint(L, H)))

    ps = list(ps)
    ds = []
    for p in ps:
        ds.append(query(*p))
    if ds.count(0) > 0: continue

    pd = zip(ps, ds)

    # For each pair, try all possible candidates.
    found = False
    for pd1, pd2 in combinations(pd, 2):
        for p in intersect(*pd1, *pd2):
            found |= query(*p) == 0
    assert found


