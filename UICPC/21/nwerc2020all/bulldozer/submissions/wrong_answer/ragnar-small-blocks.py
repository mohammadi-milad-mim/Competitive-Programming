#!/usr/bin/env python3
# @EXPECTED_RESULT@: WRONG_ANSWER, RUN_TIME_ERROR

n = int(input())
a = [0]*n + list(map(int, input().split())) + [0]*n
m = len(a)

# Stage: (x, y): horizontal position x, with y interesting cells done.
g = [[[] for _ in range(max(x, 1))] for x in a]
inf = 10**18
d = [[inf for _ in range(max(x, 1))] for x in a]


# horizontal edges with cost 0 without covering any cells
for i in range(m-1):
    if a[i] <= 1:
        g[i][0].append((i+1, 0, 0))
    else:
        g[i][a[i]-1].append((i+1, 0, 0))

# vertical edges with cost 2 for skipping
for i in range(m):
    for y in range(a[i]-1):
        g[i][y].append((i, y+1, 2))

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

d[0][0] = 0
for x in range(m):
    for y in range(max(a[x], 1)):
        for x2, y2, dist in g[x][y]:
            d[x2][y2] = min(d[x2][y2], d[x][y] + dist)

print(d[m-1][0])

