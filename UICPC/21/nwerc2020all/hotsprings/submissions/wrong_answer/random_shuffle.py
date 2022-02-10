#!/usr/bin/env python3
import random
n = int(input())
A = list(map(int, input().split()))
random.shuffle(A)
print(*A)