#!/usr/bin/env python3
n = int(input())
d = list(map(int, input().split()))
t = [list(map(int, input().split())) for _ in range(3)]

ivals = [[[0]*n for _ in range(n)] for _ in range(3)]

for p in range(3):
    for i in range(n):
        curt = 0
        for j in range(n):
            ivals[p][i][(i+j)%n] = (curt, curt+t[p][(i+j)%n])
            curt += t[p][(i+j)%n] + d[(i+j)%n]


def disjoint(I, J): return I[1] <= J[0] or J[1] <= I[0]

ok = [[[all(disjoint(P1i[k], P2i[k]) for k in range(n)) for P2i in P2]
       for P1i in P1] for (P1, P2) in zip(ivals, ivals[1:]+[ivals[0]])]

def ans():
    for i1 in range(n):
        for i2 in range(n):
            if ok[0][i1][i2]:
                for i3 in range(n):
                    if ok[1][i2][i3] and ok[2][i3][i1]:
                        return '%d %d %d' % (i1+1, i2+1, i3+1)
    return 'impossible'

print(ans())
                                      
                                      
