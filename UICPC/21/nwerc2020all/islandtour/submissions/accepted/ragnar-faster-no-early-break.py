#!/usr/bin/env python3
# Same as ragnar.py, but avoids nested functions and inlines disjoint.
from itertools import *
n = int(input())
d = list(map(int, input().split()))
ts = [list(map(int, input().split())) for _ in range(3)]
at = [(lambda l: list(zip(l[0::2], l[1::2])))([0]+list(accumulate(chain(*zip(t+t, d+d))))) for t in ts]
def test(i, j, ta, tb):
    xx, yy = ta[i][0], tb[j][0]
    ans = True
    for k in range(n):
        (x0, x1), (y0, y1) = ta[n+k if k < i else k], tb[n+k if k < j else k]
        if x1-xx > y0-yy and y1-yy > x0-xx: ans = False
    return ans
def solve(ta, tb): return [[test(i, j, ta, tb) for j in range(n)] for i in range(n)]
ps = [solve(at[i], at[(i+1)%3]) for i in range(3)]
for i, j, k in product(range(n), repeat=3):
    if ps[0][i][j] and ps[1][j][k] and ps[2][k][i]:
        print(i+1,j+1,k+1)
        exit(0)
print('impossible')
