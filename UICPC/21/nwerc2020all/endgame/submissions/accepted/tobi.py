#!/usr/bin/python3

import random

n = int(input())
ax, ay = map(int, input().split())
bx, by = map(int, input().split())
moves = set()
for _ in range(n):
    x, y = map(int, input().split())
    moves.add((x,y))

def reachable(fromx, fromy, tox, toy):
    if (fromx == tox and fromy == toy or (tox-fromx, toy-fromy) in moves):
        return True
    for x, y in moves:
        newx = fromx + x
        newy = fromy + y
        if newx <= 0 or newx > n or newy <= 0 or newy > n:
            continue
        if (tox-newx, toy-newy) in moves:
            return True
    return False

def exhaust():
    for x in range(1, n+1):
        for y in range(1, n+1):
            if not reachable(bx, by, x, y):
                return 'tie {} {}'.format(x, y)
    return None

def tries():
    for _ in range(10000):
        x = random.randint(1, n)
        y = random.randint(1, n)
        if not reachable(bx, by, x, y):
            return 'tie {} {}'.format(x, y)
    return None

if reachable(ax, ay, bx, by):
    print('Alice wins')
else:
    tie = (exhaust() if n*n < 10000 else tries())
    print(tie if tie else 'Bob wins')
