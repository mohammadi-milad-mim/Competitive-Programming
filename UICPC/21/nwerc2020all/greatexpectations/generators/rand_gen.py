#!/usr/bin/env python3
import sys
import random
from fractions import Fraction
N = int(sys.argv[1])
m = int(sys.argv[2])
sigma = float(sys.argv[3])
assert m < N
random.seed(int(sys.argv[-1]))

R = random.randint(N+1, 5*N)

def rand():
    s = '%0.6f' % (1-abs(random.gauss(0, sigma)))
    return Fraction(s)

print('%d %d %d' % (N, R, m))

while True:
    old_tricks = []
    rem = list(range(1,N))

    ok = True
    for i in range(m):
        found = False
        for attempt in range(20):
            tm = random.choice(rem)
            tricks = old_tricks + [ (tm, rand(), random.randint(0, N)) ]
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

            if prob_improve(0, 0) >= Fraction(1,26461):
                found = True
                old_tricks = tricks
                rem.remove(tm)
                break
        if not found:
            ok = False
            break
    if ok:
        for (t, p, l) in old_tricks:
            print('%d %.6f %d' % (t, p, l))
        break

