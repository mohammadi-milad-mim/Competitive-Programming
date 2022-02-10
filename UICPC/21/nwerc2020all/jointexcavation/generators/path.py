#!/usr/bin/env python3
import sys
import random

random.seed(int(sys.argv[-1]))
n = int(sys.argv[1])

order = list(range(1,n+1))
if sys.argv[2] == 'increasing':
    order = list(sorted(order))
elif sys.argv[2] == 'decreasing':
    order = list(sorted(order))[::-1]
elif sys.argv[2] == 'shuffled':
    random.shuffle(order)

print('%d %d' % (n, n-1))
for x,y in zip(order, order[1:]):
    print('%d %d' % (x,y))

