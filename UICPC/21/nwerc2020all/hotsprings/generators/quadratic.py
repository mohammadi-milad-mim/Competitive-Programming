#!/usr/bin/env python3
import sys
import random

N = int(sys.argv[1])
max_a = int(sys.argv[2])
reverse = int(sys.argv[3])

l = [-max_a]
for i in range(1, N):
    l.append(l[-1] + i)

if reverse:
    l = reversed(l)
    l = [-x for x in l]

print(N)
print(*l)
