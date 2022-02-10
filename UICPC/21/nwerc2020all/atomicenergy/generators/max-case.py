#!/usr/bin/env python3
import sys

N = int(sys.argv[1])
Q = int(sys.argv[2])
A = int(sys.argv[3])
K = int(sys.argv[4])

print(str.format("{} {}", N, Q))
print(' '.join(str(A) for _ in range(N)))
print('\n'.join(str(K - i) for i in range(Q)))
