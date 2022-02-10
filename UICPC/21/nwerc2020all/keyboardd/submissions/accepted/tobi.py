#!/usr/bin/python3
import collections
import random

count = collections.defaultdict(int)

for c in input():
    count[c] -= 1
for c in input():
    count[c] += 1

out = []
for k, v in count.items():
    if v > 0:
        out.append(k)
random.shuffle(out)
print(''.join(out))
