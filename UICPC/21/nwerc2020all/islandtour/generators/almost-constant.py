#!/usr/bin/env python3
import sys
import random

# 1 waits a seconds everywhere, except c seconds at a random spot.
# 2 waits b seconds everywhere.
# 3 waits c seconds everywhere.

# Choose b and c so that (n-1)(b+1) = 2(c+1)+1 to make solution almost unique.

n = int(sys.argv[1])
a = int(sys.argv[2])
b = int(sys.argv[3])
c = int(sys.argv[4])
seed = int(sys.argv[5])
k = 3
random.seed(seed)

print(n)
ones = [1] * n
print(*ones)
r = random.randrange(0, n)

A = []
for i in range(0, n):
    if i == r:
        A.append(c)
    else:
        A.append(a)
print(*A)

B = [b] * n
print(*B)
C = [c] * n
print(*C)
