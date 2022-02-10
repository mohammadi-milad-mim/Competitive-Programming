#!/usr/bin/env python3
import random
import sys

n = int(sys.argv[1])
width = int(sys.argv[2])
random.seed(int(sys.argv[3]))
k = (n+1)//4

col0 = 1
row0 = 1

print('%d' % n)
print('%d %d' % (2, 2))
print('%d %d' % (col0, row0))

global left
left = n

done = set((0,0))
def add(x,y):
    global left
    if (x,y) not in done:
        print('%d %d' % (x,y))
        done.add((x,y))
        left -= 1

for i in range(1,k):
    add(i, 0)
for i in range(1,k):
    add(0, i)

for row in range(1, width+1):
    for col in range(1, n+1, k):
        add(col - col0, row - row0)
for row in range(n-width+1, n+1):
    for col in range(1, n+1, k):
        add(col - col0, row - row0)
for col in range(1, width+1):
    for row in range(1, n+1, k):
        add(col - col0, row - row0)
for col in range(n-width+1, n+1):
    for row in range(1, n+1, k):
        add(col - col0, row - row0)

assert left >= 0
while left > 0:
    add(random.randint(-n+1,n-1), random.randint(-n+1,n-1))

