#!/usr/bin/env python3
import random
import sys

xmax = 10**9

n, s = map(int, sys.argv[1:])

random.seed(s)

# Three cars that almost collide at the same time:
# The first and second car collide at a/(a-1).
# The second and third car collide either at (a+1)/a or (a-1)/(a-2).
# Note that a/(a-1) - (a+1)/a = 1/(a*(a-1)).

a = xmax - random.randint(2,1000)
b = random.choice([a-1,a+1])
cars = [(-a,a-1),(0,0),(b,1-b)]

xs = set([-a,0,b])

# Some pairs of cars that quickly eliminate each other:

while len(cars)+2 <= n:
    x = random.randint(-xmax,xmax)
    if x in xs or x+1 in xs: continue
    xs.add(x)
    xs.add(x+1)
    cars.append((x,a))
    cars.append((x+1,-a))

cars.sort()

print(n)
for x, v in cars:
    print(x, v)
