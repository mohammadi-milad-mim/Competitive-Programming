#!/usr/bin/env python3

# Read the input and interaction
# Outputs the number of queries, followed by one line per query: the query point and the location of the closest active dragon ball.

# Read input
n = int(input())
ss = set()
for _ in range(n):
    x, y = map(int, input().split())
    ss.add((x,y))

# Read interaction
_ = input()
qs = []
while len(ss) > 0:
    # Query
    x, y = map(int, input()[1:].split())
    if (x,y) in ss:
        a, b = x, y
        ss.remove((x,y))
    else:
        d = 3*10**12
        for r, s in ss:
            dd = (r-x)**2 + (s-y)**2 
            if dd < d:
                d = dd
                a, b = r, s
    qs.append((x, y, a, b))

    # Answer
    input()

print(len(qs))
for q in qs: print(*q)
