#!/usr/bin/env python3
s, t=input(), list(input())
for c in s: t.remove(c)
print(*list(set(t)),sep='')
