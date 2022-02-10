#!/usr/bin/env python3
from collections import Counter

a = Counter(input())
b = Counter(input())
b.subtract(a)
print(''.join(set(b.elements())))
