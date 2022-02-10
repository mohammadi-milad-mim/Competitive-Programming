#!/usr/bin/env python3
import sys
import random
import math

r = int(sys.argv[1])
n = int(sys.argv[2])
m = int(sys.argv[3])
random.seed(int(sys.argv[-1]))

assert 5000 >= r > n > m > 0
assert m <= 50
assert r-n > m

# Uniform distribution of trick times
t = sorted(random.sample(range(1,n),m))

# Uniform distribution of probabilities
p = [random.uniform(0.000001,0.999999) for i in range(m)]

# Random always-valid recovery times
D = sorted([random.randint(0,r-n-1-m) for i in range(m)] + [0])
d = [min(1 + D[i+1] - D[i], 1000) for i in range(m)]

print('%d %d %d' % (n, r, m))
for i in range(m):
    print('%d %.6f %d' % (t[i], p[i], d[i]))

