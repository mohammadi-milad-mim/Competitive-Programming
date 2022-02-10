import math
for t in range(int(input())):
    n = int(input())
    p1 = 0
    p2 = 0
    for i in range(1,n+1,4):
        p1+=2**i
    for i in range(2,n+1,4):
        p2+=2**i
    for i in range(3,n+1,4):
        p2+=2**i
    for i in range(4,n+1,4):
        p1+=2**i
    print(abs(p1-p2))