#!/usr/bin/python3
total, partial  = map(int, input().split())
jury_diff, team_diff = map(int, input().split())

def estimate(rest):
    return (team_diff*partial + rest*(total-partial))/total

a = 0.
o = 100.
for _ in range(0, 100):
    m = (a+o)/2.
    if estimate(m) < jury_diff:
        a = m
    else:
        o = m
print('impossible' if abs(jury_diff - estimate(a)) > 1.e-6 else a)
