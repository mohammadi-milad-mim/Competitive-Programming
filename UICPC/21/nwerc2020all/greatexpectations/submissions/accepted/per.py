#!/usr/bin/env python3

(n, r, m) = map(int, input().split())
tricks = [(lambda t: (int(t[0]), float(t[1]), int(t[2])))(input().split()) for _ in range(m)]

def ok(Et):
    expt = [[0]*(r-n) for _ in range(m+1)]
    for lost in range(r-n): expt[m][lost] = n+lost
    for i in range(m-1, -1, -1):
        (ti, pi, li) = tricks[i]
        for lost in range(0, r-n):
            expt[i][lost] = (    pi*min(ti+lost+Et, expt[i+1][lost]) +
                             (1-pi)*min(ti+lost+Et, expt[i+1][lost+li] if lost+li < r-n else 1e50))
    return expt[0][0] <= Et

lo = 0
hi = 1e9
for _ in range(60):
    t = (lo+hi)/2.0
    if ok(t): hi = t
    else: lo = t

print(hi)
