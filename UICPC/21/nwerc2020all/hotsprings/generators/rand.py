#!/usr/bin/env python3
import sys
import random

N = int(sys.argv[1])
max_a = int(sys.argv[2])
seed = int(sys.argv[3])

random.seed(seed)

print(N)
A = []
for _ in range(0, N):
    A.append(random.randint(-max_a, max_a))
print(*A)

