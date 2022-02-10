#!/usr/bin/env python3
import argparse
import random

MAX_N = 2*10**5
MAX_H = 10**9

def geo(p):
    x = 0
    while random.random() > p: x += 1
    return x

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--p', type=float, default=0.5)
    parser.add_argument('--n', type=int, default=MAX_N)
    parser.add_argument('--seed', type=int, default=2019)

    args = parser.parse_args()
    random.seed(args.seed)
    h = [geo(args.p) for _ in range(args.n)]
    print(args.n)
    print(' '.join(map(str, h)))
    
if __name__=='__main__':
    main()
