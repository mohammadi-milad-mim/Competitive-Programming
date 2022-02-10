#!/usr/bin/env python3
(n, k) = map(int, input().split())
(a, s) = map(float, input().split())
ans = (n*a - s*k)/(n-k)
print(ans if 0 <= ans <= 100 else 'impossible')

