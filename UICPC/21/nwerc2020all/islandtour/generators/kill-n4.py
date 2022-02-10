#!/usr/bin/env python3
import sys


n = int(sys.argv[1])
a = int(sys.argv[2])

def printrow(x):
    print(str(x) + ((' '+str(x)) * (n - 1)))

print(n)
printrow(1)
for i in range(3):
    printrow(n-1 if a == i else 1)
