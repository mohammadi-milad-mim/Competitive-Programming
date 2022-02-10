#!/usr/bin/env python3
import sys
from random import seed, randrange

seed(int(sys.argv[1]))

N = 100
A = 10**9
Q = 10**5

def get(n):
    M = 10**6
    def v(i):
        r = i * M
        if i % 2 == 1 and i != 93:
            r += M
        elif i % 2 == 0:
            r += 1
        return r
    return [v(i) for i in range(1, N+1)]

print(str.format("{} {}", N, Q))
print(' '.join(map(str, get(N))))
for _ in range(Q):
    print(randrange(1, A+1))
