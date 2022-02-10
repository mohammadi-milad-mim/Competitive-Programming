#!/usr/bin/env python3
from sys import stderr
from math import sqrt

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
    assert p1[1] in [L, H] and p1[1] in [L, H]
    if (d1 - d2 + 1) % 2 != 0: return None
    dx = (d1 - d2 + 1) // 2

    # TODO: There may be a bug here:
    # When d1 and d2 are distances to different points, can this be negative?
    dy = round(sqrt(d1 - dx * dx))
    if dx * dx + dy * dy != d1: return None
    if p1[1] == p2[1]: dx, dy = dy, dx
    # Move (dx, dy) towards the center.
    x, y = (dx if p1[0] == 0 else H - dx, dy if p1[1] == 0 else H - dy)
    return (x, y)

ps = [
    ((0, 0), (0, 1)),
    ((0, 0), (1, 0)),
    ((0, H), (0, H - 1)),
    ((0, H), (1, H)),
    ((H, 0), (H - 1, 0)),
    ((H, 0), (H, 1)),
    ((H, H), (H - 1, H)),
    ((H, H), (H, H - 1)),
]
while n > 0:
    for p, q in ps:
        d1 = query(*p)
        if d1 == 0: continue
        d2 = query(*q)
        r = intersect(p, d1, q, d2)
        if d1 > 0 and d2 > 0 and r:
            assert query(*r) == 0
