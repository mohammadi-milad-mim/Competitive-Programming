#!/usr/bin/env python3
import heapq
from fractions import Fraction

n = int(input())
C = [[-1<<60, 0, 0]] + [list(map(int, input().split()))+[i+1] for i in range(n)] + [[1<<60, 1<<60, 0]]
C.sort()

Q = []
nxt = list(range(1, n+3))
prv = list(range(-1, n+1))
alive = [0] + [1]*n + [0]

def consider(i, j):
    (x1, v1, _) = C[i]
    (x2, v2, _) = C[j]
    if v1 > v2:
        heapq.heappush(Q, (Fraction(x2-x1, v1-v2), i, j))

def kill(i, j):
    if not alive[i] or not alive[j]: return
    alive[i] = alive[j] = 0
    nxt[prv[i]] = nxt[j]
    prv[nxt[j]] = prv[i]
    consider(prv[i], nxt[j])
    
for i in range(1, n): consider(i, i+1)
while Q:
    (_, i, j) = heapq.heappop(Q)
    kill(i, j)

print(sum(alive))
print(' '.join(map(str, sorted(C[i][2] for i in range(1, n+1) if alive[i]))))
