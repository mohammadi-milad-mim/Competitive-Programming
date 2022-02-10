#!/usr/bin/env python3

n = int(input())
a = sorted(map(int, input().split()))

m = n//2
b = [0] * n
b[::2] = a[m:]
b[1::2] = a[m-1::-1]
print(' '.join(str(x) for x in b))
