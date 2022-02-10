#!/usr/bin/env python3
import argparse
import random

MAX_N = 2*10**5

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--blocks', type=int, default=MAX_N)
    parser.add_argument('--n', type=int, default=MAX_N)
    parser.add_argument('--seed', type=int, default=2019)

    args = parser.parse_args()
    random.seed(args.seed)
    h = [0]*args.n
    for _ in range(args.blocks):
        h[random.randint(0, args.n-1)] += 1
    print(args.n)
    print(' '.join(map(str, h)))
    
if __name__=='__main__':
    main()
