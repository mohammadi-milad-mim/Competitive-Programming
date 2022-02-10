import math
for T in range(int(input())):
    s = list(input())
    n = len(s)
    for i in range(1,n+1):
        temp = s[:i]*(math.ceil(n/i))
        if temp[:n]==s:
            print(i)
            break