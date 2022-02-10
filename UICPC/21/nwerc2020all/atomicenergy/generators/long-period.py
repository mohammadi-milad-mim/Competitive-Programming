#!/usr/bin/env python3
import sys
from random import randrange

N = 100
A = 10**9
Q = 10**5

T = 9000

while True:
    a = [0] + [randrange(1, A+1) for _ in range(N)] + [0]*(N*(N-1))
    for j in range(N+1, N*N+1):
        a[j] = a[j-1]+a[1]
        for i in range(2, N+1):
            a[j] = min(a[j], a[j-i]+a[i])

    m = 1
    for i in range(2, N+1):
        if a[i]*m < a[m]*i:
            m = i
    b = m
    for i in range(N+1, N*N+1):
        if a[i] < a[i-m] + a[m]:
            b = i

    print(b, file=sys.stderr)
    if b > T:
        print(str.format("{} {}", N, Q))
        print(' '.join(map(str, a[1:N+1])))
        for _ in range(Q):
            print(b + m*randrange(0, (A-b) // m))
        break
