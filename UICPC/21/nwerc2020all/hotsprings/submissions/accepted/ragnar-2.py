#!/usr/bin/env python3
import itertools
n, v = int(input()), sorted(map(int, input().split()))
print(*(x for x in itertools.chain(*itertools.zip_longest(v[(n-1)//2::-1], v[(n+1)//2:])) if x is not None))

