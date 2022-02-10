#!/usr/bin/env python3
import argparse
import random

MAX_N = 2*10**5
MAX_H = 10**9

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--minh', type=int, default=0)
    parser.add_argument('--maxh', type=int, default=MAX_H)
    parser.add_argument('--minn', type=int, default=1)
    parser.add_argument('--maxn', type=int, default=MAX_N)
    parser.add_argument('--seed', type=int, default=2019)

    args = parser.parse_args()
    random.seed(args.seed)
    n = random.randint(args.minn, args.maxn)
    h = [random.randint(args.minh, args.maxh) for _ in range(n)]
    print(n)
    print(' '.join(map(str, h)))
    
if __name__=='__main__':
    main()
