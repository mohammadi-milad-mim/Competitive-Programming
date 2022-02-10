#!/usr/bin/env python3
import sys

n, m = map(int, input().split())
adj = [[] for _ in range(n+1)]
children = [[] for _ in range(n+1)]
sz = [0]*(n+1)
for _ in range(m):
    (u, v) = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

Q = [(1, 0)]
sz[1] = 1
while Q:
    (u, par) = Q.pop()
    while True:
        if not adj[u]:
            sz[par] += sz[u]
            break
        v = adj[u].pop()
        if not sz[v]:
            sz[v] = 1
            children[u].append(v)
            Q.append((u, par))
            Q.append((v, u))
            break

A = []
B = []
P = []
def add_tree(v, par):
    global A, B
    Q = [(v, par)]
    while Q:
        (v, par) = Q.pop()
        A.append(v)
        for w in children[v]: Q.append((w, v))
    if len(A) > len(B): (A, B) = (B, A)

(at, par) = (1, 0)
while True:
    if len(A) + sz[at] == len(B):
        add_tree(at, par)
        break
    P.append(at)
    if not children[at]: break
    max_v = children[at].pop()
    for v in children[at]:
        if sz[v] > sz[max_v]: (v, max_v) = (max_v, v)
        add_tree(v, -1)
    (at, par) = (max_v, at)

print(len(P), len(A))
print(' '.join(map(str, P)))
print(' '.join(map(str, A)))
print(' '.join(map(str, B)))
