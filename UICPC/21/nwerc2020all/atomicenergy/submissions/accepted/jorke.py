#!/usr/bin/env python3
# Runs in O(n^3 + q),
#  where n is the amount of given elements and q the amount of queries.

# Reading input
# O(n)
n,q = [int(i) for i in input().split()]
a = [0] + [int(i) for i in input().split()] # additional 0 since a_i is one-based

# Finding the sequence period m
# O(n)
m = 1
for i in range(1,n+1):
    if a[i]*m < a[m]*i:
        m = i

# Precomputing values up to n**2
# O(n^3)
for i in range(n+1, n**2 + 1):
    minimal = a[1] + a[i-1]
    for j in range(2,n+1):
        minimal = min(minimal, a[j] + a[i-j])
    a.append(minimal)

# Answering queries
# O(q)
for i in range(q):
    k = int(input())
    x = min(k, n**2 - ((n**2-k) % m))
    y = (k - x) // m
    print(a[x] + y*a[m])
