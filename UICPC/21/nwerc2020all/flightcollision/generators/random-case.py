#!/usr/bin/env python3
import random
import sys

n, xmax, s = map(int, sys.argv[1:])
random.seed(s)

x = random.sample(range(-xmax,xmax+1), n)
v = [random.randint(-xmax,xmax) for _ in range(n)]

indices = list(range(n))
indices.sort(key=lambda i: x[i])

print(n)
for i in indices:
    print(x[i], v[i])
