#!/usr/bin/env python3
import sys
import random

# Each person has two different times in two segments

n = int(sys.argv[1])
seed = int(sys.argv[2])
k = 3
random.seed(seed)

print(n)
ones = [1] * n
print(*ones)

for i in range(k):
    t1 = random.randint(1, 10**6)
    t2 = random.randint(1, 10**6)
    L = random.randint(0, n//2)
    R = random.randint(n//2, n-1)

    T = []
    for j in range(0, n):
        if j >= L and j <= R:
            T.append(t2)
        else:
            T.append(t1)
    print(*T)