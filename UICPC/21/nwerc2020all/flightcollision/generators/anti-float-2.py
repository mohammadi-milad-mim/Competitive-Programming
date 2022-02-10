#!/usr/bin/env python3
import random
import sys

# There are several groups of cars, where in each group exactly one car
# survives and there are no collisions between cars from different groups.
# Each group is created such that the collision times between adjacent cars are
# 1/a, 1/(a+1), 1/(a+2) ... in some order, where some large integer a.

xmax = 10**9

n, s = map(int, sys.argv[1:])

random.seed(s)

def has_triple(w):
    n = len(w)
    for i in range(n):
        for j in range(i):
            for k in range(j):
                if (w[j]-w[i])*(k-j) == (w[k]-w[j])*(j-i):
                    return True
    return False

def survivor(perm):
    k = len(perm)+1
    elim = [False] * k
    for i in range(k-1):
        j = perm.index(i)
        if elim[j] or elim[j+1]:
            continue
        elim[j] = elim[j+1] = True
    return elim.index(False)

print(n)

x = 0
v = 0
while n > 0:
    k = random.choice([1,3,5,7,9])
    if k > n: continue
    
    perm = list(range(k-1))
    random.shuffle(perm)
    
    j = survivor(perm)

    pref = [0]
    for i in perm:
        pref.append(pref[-1]+i)

    a = xmax
    for i in range(k):
        # abs(v + (j-i)*a + pref[j]-pref[i]) <= xmax
        if i < j:
            a = min(a, (xmax - v - (pref[j]-pref[i])) // (j-i))
        if j < i:
            a = min(a, (xmax + v + (pref[j]-pref[i])) // (i-j))
    a -= random.randint(0,1000)
    
    w = [0] * k
    for i in range(k):
        w[i] = v + (j-i)*a + pref[j]-pref[i]
        assert(abs(w[i]) <= xmax)

    if has_triple(w):
        continue

    n -= k
    for i in range(k):
        print(x+i, w[i])

    x += 1000
    v += 1000
