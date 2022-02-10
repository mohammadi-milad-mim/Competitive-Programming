#!/usr/bin/env python3
from fractions import Fraction
n, q = map(int, input().split())
a = [0] + list(map(int, input().split()))
r, d = min((Fraction(ai, i+1), i+1) for i, ai in enumerate(a[1:]))
l = n*n
for i in range(n+1, l): a.append(min(a[j] + a[i-j] for j in range(1, min(i, n+1))))
for q in (int(input()) for _ in range(q)):
    if q < l: print(a[q])
    else:
        i = (l-1-q%d)//d*d+q%d
        print(a[i] + (q-i)//d * a[d])
