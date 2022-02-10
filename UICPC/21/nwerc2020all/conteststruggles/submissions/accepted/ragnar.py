#!/usr/bin/env python3
n, k = map(int, input().split())
a, b = map(float, input().split())
v = (n*a-k*b)/(n-k)
print(f'{v:.12}' if 0<=v<=100 else 'impossible')
