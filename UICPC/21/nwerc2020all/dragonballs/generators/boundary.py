#!/usr/bin/env python3
import random
import sys
_, n, m, s = sys.argv
# number of points; boundary; seed
n, m, s = int(n), int(m), int(s)
random.seed(int(s))
print(n)

ps = set()
while len(ps) < n:
    x = random.randint(0, m)
    y = 0
    if random.randint(0, 1) == 1: x, y = y, x
    if random.randint(0, 1) == 1: x, y = m - x, m - y

    ps.add((x, y))
ps = sorted(ps)
for p in ps:
    print(*p)

