#!/usr/bin/env python3
A = input()
B = input()
print(''.join(x for x in map(chr, range(32, 127)) if A.count(x) < B.count(x)))
