#!/usr/bin/env python3
n, m = map(int, input().split())
g = [[] for _ in range(n+1)]
for _ in range(m):
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)
A, p, B = set(range(1, n+1)), [], set()
def isdone():
    global A, p, B
    if len(A) != len(B): return
    print(len(p), len(A))
    print(*p)
    print(*A)
    print(*B)
    exit(0)
q = [1]
while len(q) > 0:
    u = q.pop()
    assert u != 0
    if u < 0:
        B.add(p.pop())
        isdone()
        continue
    if u not in A: continue
    q.append(-u)
    A.remove(u)
    p.append(u)
    isdone()
    for v in g[p[-1]]:
        if v in A: q.append(v)
