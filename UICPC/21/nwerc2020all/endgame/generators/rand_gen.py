#!/usr/bin/env python3
import sys
import random

N = int(sys.argv[1])
random.seed(int(sys.argv[-1]))

print('%d' % N)

ar = random.randint(1, N)
ac = random.randint(1, N)

while True:
    br = random.randint(1, N)
    bc = random.randint(1, N)
    if (ar,ac) != (br,bc):
        break

print('%d %d' % (ar,ac))
print('%d %d' % (br,bc))

moves = set()
while len(moves) < N:
    moves.add((random.randint(-N+1, N-1),
               random.randint(-N+1, N-1)))

moves = list(moves)
random.shuffle(moves)
for (x,y) in moves:
    print('%d %d' % (x,y))

