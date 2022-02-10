#!/usr/bin/env python3
import argparse
import random
import math

MAX_N = 2*10**5
MAX_H = 10**9

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--seed', type=int, default=2019)
    parser.add_argument('zero', type=int)
    parser.add_argument('small', type=int)  # between 1 and 10
    parser.add_argument('medium', type=int) # between 1 and sqrt(n)
    parser.add_argument('large', type=int)  # between 1 and 5*n
    parser.add_argument('huge', type=int)   # between 1 and MAX_H

    args = parser.parse_args()
    random.seed(args.seed)
    n = args.zero + args.small + args.medium + args.large + args.huge
    assert 1 <= n <= MAX_N
    sqrtn = int(math.sqrt(n))
    
    h = []
    for _ in range(args.zero): h.append(0)
    for _ in range(args.small): h.append(random.randint(1, 10))
    for _ in range(args.medium): h.append(random.randint(1, sqrtn))
    for _ in range(args.large): h.append(random.randint(1, 5*n))
    for _ in range(args.huge): h.append(random.randint(1, MAX_H))
    random.shuffle(h)

    print(n)
    print(' '.join(map(str, h)))
    
if __name__=='__main__':
    main()
