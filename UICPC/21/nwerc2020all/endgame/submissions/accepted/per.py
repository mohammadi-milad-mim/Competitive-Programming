#!/usr/bin/env python3
import random
random.seed(2019)

n = int(input())
(ar, ac) = map(int, input().split())
(br, bc) = map(int, input().split())
moves = set(tuple(map(int, input().split())) for _ in range(n))

def can_go(r1, c1, r2, c2):
    return any((r1 + dr == r2 and c1 + dc == c2) or
               (1 <= r1 + dr <= n and 1 <= c1 + dc <= n and (r2-r1-dr, c2-c1-dc) in moves)
               for (dr, dc) in moves)

def ans():
    if can_go(ar, ac, br, bc): return 'Alice wins'
    for _ in range(100):
        (nr, nc) = (random.randint(1, n), random.randint(1, n))
        if (nr, nc) != (br, bc) and not can_go(br, bc, nr, nc): return 'tie %d %d' % (nr, nc)
    return 'Bob wins'

print(ans())


