#!/usr/bin/env python3
from heapq import *
from sys import stderr

n = int(input())
cs = sorted([list(map(int, input().split()))+[i] for i in range(n)])

class F:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __lt__(self, other):
        return self.x * other.y < other.x * self.y

q = []
def intersect(i, j):
    dv = cs[i][1] - cs[j][1]
    if dv <= 0: return None
    return (F(cs[j][0] - cs[i][0], dv), (i, j))

for i in range(n-1):
    t = intersect(i, i+1)
    if t: heappush(q, t)

nxt = [[i+1] for i in range(n)]
prev= [[i-1] for i in range(n)]

alive = [True] * n
while len(q) > 0:
    t, (i, j) = heappop(q)
    if not alive[i] or not alive[j]: continue
    alive[i] = alive[j] = False
    assert i < j
    pp = prev[i]
    pi = pp[0]
    nn = nxt[j]
    ni = nn[0]
    if pi >= 0 and ni < n:
        nxt[pi] = nn
        prev[ni] = pp
        t = intersect(pi, ni)
        if t: heappush(q, t)

print(alive.count(True), *sorted(cs[i][2]+1 for i in range(n) if alive[i]))
