#!/usr/bin/python3
import random
import string
import sys
import os

MAXN = 100
MAXQ = 10**5
MAXA = 10**9
MAXK = 10**9

if len(sys.argv) != 3:
    print('Call with',sys.argv[0],"<filename> <seed>")
    print('e.g.',sys.argv[0],"data/secret/01-random.in 42")
    exit(1)

fn = sys.argv[1]
seed = sys.argv[2]

random.seed(seed)
with open(fn, 'w', newline='\n') as in_file:
    n = random.randint(1, MAXN)
    q = random.randint(1, MAXQ)
    print(n,q,file=in_file)
    print(' '.join([str(random.randint(1,MAXA)) for i in range(n)]),file=in_file)
    for i in range(q):
        print(random.randint(1,MAXK),file=in_file)
