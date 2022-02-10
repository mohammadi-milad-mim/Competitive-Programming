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

# Uniform distribution of trick times
t = sorted(random.sample(range(1,n),m))

# Random recovery times between 1 and 1000
d = [random.randint(1,1000) for i in range(m)]

# Logarithmic uniform distribution of the p_i which multiplies to approximately 1/49999
maxlogp = math.log(49999)
logp = sorted([random.uniform(0,maxlogp) for i in range(m)] + [0])
p = [math.exp(logp[i] - logp[i+1]) for i in range(m)]

print('%d %d %d' % (n, r, m))
for i in range(m):
    print('%d %.6f %d' % (t[i], p[i] + 0.0000005, d[i]))

