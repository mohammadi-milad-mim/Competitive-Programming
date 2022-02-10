#!/usr/bin/env python3

def min_jmp(T, i, v0):
    T[i][0] = v0;
    for b in range(logn):
        T[i][b+1] = min(T[i][b], T[max(i-(1<<b), 0)][b])

def prev_smaller(T, i, v):
    for b in range(logn, -1, -1):
        if i < 0: break
        if T[i][b] >= v: i -= 1<<b
    return max(i, -1)


n = int(input())
logn = 0
while (2<<logn) <= n: logn += 1

a = list(map(int, input().split()))
a_sum = [0]*(n+1)
for i in range(n): a_sum[i+1] = a_sum[i] + a[i]

surplus = [[0]*(logn+1) for _ in range(n+1)]
deficit = [[0]*(logn+1) for _ in range(n+1)]
opt_glide = [[0]*(logn+1) for _ in range(n+1)]
opt = [0]*(n+1)
ans = 1<<60

for i in range(1, n+1):
    opt[i] = max(a_sum[i]-1, 0)
    if a[i-1] == 0: opt[i] = min(opt[i], opt[i-1])
    r = prev_smaller(surplus, i-1, a_sum[i]-i+1)
    if r >= 0:
        l = prev_smaller(deficit, r-1, i-a_sum[i])
        b = 0
        while (2<<b) < r-l: b += 1
        opt[i] = min(opt[i], 2*a_sum[i] - i - 1 + min(opt_glide[r][b],
                                                      opt_glide[l+(1<<b)][b]))
    ans = min(ans, opt[i] + max(a_sum[n] - a_sum[i] - 1, 0))
    min_jmp(surplus, i, a_sum[i]-i)
    min_jmp(deficit, i, i-a_sum[i])
    min_jmp(opt_glide, i, opt[i] - 2*a_sum[i] + i)

print(ans)
