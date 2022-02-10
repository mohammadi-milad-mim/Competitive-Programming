#!/usr/bin/env python3
import sys

n, v = map(int, sys.argv[1:])

print(n)
for i in range(n):
    print(i, v)
