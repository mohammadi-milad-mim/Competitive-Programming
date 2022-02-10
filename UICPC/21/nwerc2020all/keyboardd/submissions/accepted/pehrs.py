#!/usr/bin/python3
from collections import defaultdict
res = defaultdict(int)
orig = input()
typoed = input()
for c in typoed:
    res[c] += 1
for c in orig:
    res[c] -= 1
out = ""
for k, v in res.items():
    if v > 0:
        out += k
print(out)
