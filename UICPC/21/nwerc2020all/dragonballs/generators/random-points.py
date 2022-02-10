#!/usr/bin/env python3
import random
import sys
_, n, m, s = sys.argv
n, m, s = int(n), int(m), int(s)
random.seed(int(s))
print(n)

ps = set()
while len(ps) < n: ps.add((random.randint(0, m), random.randint(0, m)))
ps = sorted(ps)
for p in ps:
    print(*p)

