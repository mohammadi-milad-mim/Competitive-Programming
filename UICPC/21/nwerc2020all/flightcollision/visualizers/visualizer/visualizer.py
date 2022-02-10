#!/usr/bin/env python3
import heapq
from fractions import Fraction
import sys

import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt


# Based on per.py, adapted by Jeroen for plotting the solution

if len(sys.argv) <= 1:
    print("Usage:",sys.argv[0],"name")
    exit()

with open(sys.argv[1]+'.in', 'r') as file:
    input_lines = [line.strip() for line in file]

# Solving part
n = int(input_lines[0])
if n >= 100:
    sys.exit(0)
C = [[-1<<60, 0, 0]] + [list(map(int, input_lines[i+1].split()))+[i+1] for i in range(n)] + [[1<<60, 1<<60, 0]]
C.sort()

Q = []
nxt = list(range(1, n+3))
prv = list(range(-1, n+1))
alive = [0] + [1]*n + [0]
dieat = [0] + [-1]*n + [0]
maxtime = 0

def consider(i, j):
    (x1, v1, _) = C[i]
    (x2, v2, _) = C[j]
    if v1 > v2:
        heapq.heappush(Q, (Fraction(x2-x1, v1-v2), i, j))

def kill(f, i, j):
    global maxtime
    if not alive[i] or not alive[j]: return
    alive[i] = alive[j] = 0
    dieat[i] = dieat[j] = f
    maxtime = max(maxtime, f)
    nxt[prv[i]] = nxt[j]
    prv[nxt[j]] = prv[i]
    consider(prv[i], nxt[j])

for i in range(1, n): consider(i, i+1)
while Q:
    (f, i, j) = heapq.heappop(Q)
    kill(f, i, j)

# Plotting part
maxtime = maxtime * 1.1
for i in range(1,n+1):
    if alive[i]:
        plt.plot([0, maxtime], [C[i][0], C[i][0] + maxtime * C[i][1]], color='green')
    else:
        plt.plot([0, dieat[i]], [C[i][0], C[i][0] + dieat[i] * C[i][1]], color='red')
        plt.plot([dieat[i], maxtime], [C[i][0] + dieat[i] * C[i][1], C[i][0] + maxtime * C[i][1]], color='black', linestyle='dashed', linewidth=1)

plt.savefig(sys.argv[1]+'.png')

