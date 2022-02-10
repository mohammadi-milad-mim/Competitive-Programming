#!/usr/bin/env python3
from random import seed, randint
seed(31415)
n = int(input())
R = lambda: list(map(int, input().split()))
sr, sc = R()
tr, tc = R()
m = set(tuple(R()) for _ in range(n))
m.add((0,0))
def win(x):
    print(f'{x} wins')
    exit(0)
def is_move(sr, sc, tr, tc):
    global m
    r, c = tr-sr, tc-sc
    if (r, c) in m: return True
    for dr, dc in m:
        if sr + dr <= 0 or sc + dc <= 0 or sr+dr > n or sc+dc > n: continue
        if (-(tr-sr-dr), -(tc-sc-dc)) in m: return True
    return False
if is_move(sr, sc, tr, tc): win('Alice')
for i in range(100):
    r = randint(1, n)
    c = randint(1, n)
    tie = True
    if is_move(tr, tc, r, c): continue
    print(f'tie {r} {c}')
    exit(0)
win('Bob')
