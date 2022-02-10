#!/usr/bin/env python3
import sys
import random

N = int(sys.argv[1])
max_a = int(sys.argv[2])
reverse = int(sys.argv[3])

step = 2*max_a//(N-1)
l = [-max_a + i * step for i in range(N)]

if reverse: l = reversed(l)

print(N)
print(*l)
