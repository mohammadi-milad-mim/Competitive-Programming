#!/usr/bin/env python3
from collections import defaultdict

n = int(input())
# Interesting values are in a[1:n+1]
a = [0] + list(map(int, input().split())) + [0]

# State (x, y): horizontal position x, with y non-bottom cells done.
g = [defaultdict(list) for x in a]
d = [defaultdict(lambda: 10**18) for x in a]

# For each empty cell, add an edge to the block on the left that would end here by sliding right.
# The top of a stack slides right; the bottom of a stack slides left.
# (pos, cur_height) pairs.
stack = []
for i in range(1, n+1):
    if a[i] > 1: stack.append((i, a[i]-1))
    elif a[i] == 1 or len(stack) == 0: continue
    else:
        x, y = stack[-1]
        stack[-1] = (x, y-1)
        if y == 1: stack.pop()
        # NOTE: We need i+1 here, since column i has now been taken and cannot be reused for sliding from the other side.
        g[x][y-1].append((i+1, 0, i-x))

# Now same in reverse: add an edge to the block on the right that would end here by sliding left.
stack = []
for i in range(n+1, -1,  -1):
    if a[i] > 1: stack.append((i, a[i]-1, 0))
    elif a[i] == 1 or len(stack) == 0: continue
    else:
        x, y, z = stack[-1]
        stack[-1] = (x, y, z+1)
        if z == y-1: stack.pop()
        g[i][0].append((x, z+1, x-i))

# Add edges for sliding a number of full stacks to the left.
t = 0
for i in range(1, n+1):
    if a[i] > 0:
        t += a[i]
        if t > i: g[0][0].append((i, a[i]-1, t-1))

# Add edges for sliding a number of full stacks to the right.
t = 0
for i in range(n+1, 0, -1):
    if a[i] > 0:
        t += a[i]
        if t > n+1-i: g[i][0].append((n+1, 0, t-1))

# horizontal edges with cost 0 without covering any cells
for i in range(n+1):
    if a[i] <= 1: g[i][0].append((i+1, 0, 0))
    else: g[i][a[i]-1].append((i+1, 0, 0))

# vertical edges with cost 2 for skipping
for i in range(1, n+1):
    last = None
    for y in sorted(g[i].keys()):
        if last is not None: g[i][last].append((i, y, 2*(y-last)))
        last = y

d[0][0] = 0
for x in range(n+2):
    for y in sorted(g[x].keys()):
        for x2, y2, dist in g[x][y]:
            d[x2][y2] = min(d[x2][y2], d[x][y] + dist)

for i in range(0, n+2): print(i, g[i])
for i in range(0, n+2): print(i, d[i])

print(d[n+1][0])
