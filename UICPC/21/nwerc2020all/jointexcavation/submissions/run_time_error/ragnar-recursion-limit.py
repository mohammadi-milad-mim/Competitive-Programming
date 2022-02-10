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
def dfs(u):
    global A, p, B
    A.remove(u)
    p.append(u)
    isdone()
    for v in g[u]:
        if v in A: dfs(v)
    B.add(p.pop())
    isdone()
dfs(1)
