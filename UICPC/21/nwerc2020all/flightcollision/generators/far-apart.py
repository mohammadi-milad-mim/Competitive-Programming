#!/usr/bin/env python3
import random
import sys

xmax = 10**9

s = int(sys.argv[1])

v = [xmax,xmax-1]

print(2)
print(-xmax, v[s%2])
print(xmax, v[s//2])
