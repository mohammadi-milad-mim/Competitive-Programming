#!/usr/bin/env python3
import sys
import random

N = int(sys.argv[1])
part1 = int(sys.argv[2])
seed = int(sys.argv[3])

max_a = 100000

random.seed(seed)

print(N)
A = []
small = set(random.sample(range(0, N), part1))
for i in range(0, N):
    if i in small:
        A.append(random.randint(-max_a, -max_a//2))
    else:
        A.append(random.randint(max_a//2, max_a))
print(*A)
