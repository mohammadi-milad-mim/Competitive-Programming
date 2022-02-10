#!/usr/bin/env python3
import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*$', line)
N = int(line)
assert 2 <= N <= 10**5

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*$', line)
ar, ac = map(int, line.split())
assert 1 <= ar <= N
assert 1 <= ac <= N

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*$', line)
br, bc = map(int, line.split())
assert 1 <= br <= N
assert 1 <= bc <= N

assert (ar,ac) != (br,bc)

seen = set()
for i in range(N):
    line = sys.stdin.readline()
    assert re.match('^(0|-?[1-9][0-9]*) (0|-?[1-9][0-9]*)$', line)
    ri, ci = map(int, line.split())
    assert -N < ri < N
    assert -N < ci < N
    assert (ri, ci) not in seen
    seen.add((ri, ci))

assert not sys.stdin.read()
sys.exit(42)
