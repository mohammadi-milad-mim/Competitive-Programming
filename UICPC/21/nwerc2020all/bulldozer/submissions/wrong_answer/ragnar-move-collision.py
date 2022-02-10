#!/usr/bin/env python3
from collections import defaultdict

n = int(input())
a = [0]*1 + list(map(int, input().split())) + [0]*1
m = len(a)

# Stage: (x, y): horizontal position x, with y interesting cells done.
g = [defaultdict(list) for x in a]
inf = 10**18
d = [defaultdict(lambda: inf) for x in a]


# For each empty cell, add an edge to the block on the left that would end here by sliding right.
# The top of a stack slides right; the bottom of a stack slides left.
# (pos, cur_height) pairs.
stack = []
for i in range(m):
    if a[i] > 1: stack.append((i, a[i]-1))
    elif a[i] == 1 or len(stack) == 0: continue
    else:
        x, y = stack[-1]
        assert y > 0
        assert y <= a[x]
        stack[-1] = (x, y-1)
        if y == 1: stack.pop()

        g[x][y-1].append((i, 0, i-x))

# Now same in reverse: add an edge to the block on the right that would end here by sliding left.
stack = []
for i in range(m-1, -1,  -1):
    if a[i] > 1: stack.append((i, a[i]-1, 0))
    elif a[i] == 1 or len(stack) == 0: continue
    else:
        x, y, z = stack[-1]
        assert y > 0
        assert y <= a[x]
        assert 0 <= z and z < y
        stack[-1] = (x, y, z+1)
        if z == y-1: stack.pop()

        g[i][0].append((x, z+1, x-i))

g[0][0] = []
g[-1][0] = []

# horizontal edges with cost 0 without covering any cells
for i in range(m-1):
    if a[i] <= 1:
        g[i][0].append((i+1, 0, 0))
    else:
        g[i][a[i]-1].append((i+1, 0, 0))

# Add edges for sliding a number of full stacks to the left.
t = 0
for i in range(1, m):
    if a[i] > 0:
        t += a[i]
        if t > i:
            g[0][0].append((i, a[i]-1, t-1))

# Add edges for sliding a number of full stacks to the right.
t = 0
for i in range(m-1, 0, -1):
    if a[i] > 0:
        t += a[i]
        if t > m-1-i:
            g[i][0].append((m-1, 0, t-1))


# vertical edges with cost 2 for skipping
for i in range(1, m-1):
    last = None
    for y in sorted(g[i].keys()):
        if last is not None: g[i][last].append((i, y, 2*(y-last)))
        last = y

for i in range(m): print(i, g[i])

d[0][0] = 0
for x in range(m):
    for y in sorted(g[x]):
        for x2, y2, dist in g[x][y]:
            d[x2][y2] = min(d[x2][y2], d[x][y] + dist)

for i in range(m): print(i, d[i])

print(d[m-1][0])

