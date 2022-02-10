#!/usr/bin/env python3
import sys

n = int(sys.argv[1])

print(n)
for i in range(n):
    print(i, -1 if i > n/2 else 1)
