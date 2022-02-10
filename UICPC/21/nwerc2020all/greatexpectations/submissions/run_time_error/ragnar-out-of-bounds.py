#!/usr/bin/env python3
n, r, m = map(int, input().split())
ts = []
for _ in range(m):
    t, p, l = input().split()
    t, p, l = int(t), float(p), int(l)
    ts.append((t, p, l))

N = max(n, 5*r)

bl = n
bh = n * 50000
for bs in range(40):
    e = (bl + bh) / 2
    v = [[1e30 for _ in range(N)] for _2 in range(m+1)]
    for i in range(r): v[m][i] = 0
    last_t = n
    i = len(ts)
    for t, p, l in reversed(ts):
        i -= 1
        for time in range(r):
            dt = last_t - t
            v[i][time] = (
                # success
                p * (dt + v[i+1][time+dt])
                # failure: continue or start over
                + (1 - p) * min(l + dt + v[i+1][time+dt+l], e))
        last_t = t

    e0 = last_t + v[0][last_t]
    if e0 > e: bl = e
    else: bh = e
print(e)
