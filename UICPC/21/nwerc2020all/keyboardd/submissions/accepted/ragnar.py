#!/usr/bin/env python3
s, t=input(), list(input())
for c in s:
    while t[0] != c: t = t[1:] + t[:1]
    t.remove(c)
print(*list(set(t)),sep='')
