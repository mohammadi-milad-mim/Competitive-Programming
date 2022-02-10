#!/usr/bin/env python3
import random
s, t=input(), list(input())
for c in s:
    while t[0] != c: t = t[1:] + t[:1]
    t.remove(c)
t = list(set(t))
random.shuffle(t)
print(*t, sep='')
