#!/usr/bin/env python3
import sys
import re
from fractions import Fraction

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]* [1-9][0-9]*$', line)
N, R, m = map(int, line.split())

assert 2 <= N < R <= 5000
assert 1 <= m <= 50

times = set()
tricks = []
for i in range(m):
    line = sys.stdin.readline()
    assert re.match('^(0|[1-9][0-9]*) 0\.[0-9]+ (0|[1-9][0-9]*)$', line)
    t, p, l = line.split()
    t = int(t)
    p = Fraction(p)
    l = int(l)

    assert 0 < t < N
    assert 0 < p < 1
    assert 0 <= l
    assert t not in times
    times.add(t)
    tricks.append((t, p, l))

tricks = sorted(tricks, key=lambda x: x[0])
mem = {}

def prob_improve(next_trick, total_time):
    key = (next_trick, total_time)
    if key in mem:
        return mem[key]

    last_trick_time = 0 if next_trick == 0 else tricks[next_trick-1][0]
    next_trick_time = N if next_trick == len(tricks) else tricks[next_trick][0]
    total_time += next_trick_time - last_trick_time

    if total_time >= R:
        return Fraction(0)

    if next_trick == len(tricks):
        return Fraction(1)

    prob = tricks[next_trick][1]
    penalty = tricks[next_trick][2]
    res = prob * prob_improve(next_trick+1, total_time) + (1-prob) * prob_improve(next_trick+1, total_time+penalty)
    mem[key] = res
    return res

assert prob_improve(0, 0) >= Fraction(1,50000)

assert not sys.stdin.read()
sys.exit(42)

