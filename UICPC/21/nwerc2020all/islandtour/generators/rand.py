#!/usr/bin/env python3
import sys
import random

n = int(sys.argv[1])
max_w = int(sys.argv[2])
seed = int(sys.argv[3])
k = 3
random.seed(seed)

print(n)
for _ in range(k+1):
    A = []
    for i in range(n):
        A.append(random.randint(1, max_w))
    print(*A)

