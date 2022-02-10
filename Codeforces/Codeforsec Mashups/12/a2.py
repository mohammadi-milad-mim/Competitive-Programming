for t in range(int(input())):
    n = int(input())
    m = n//2
    p2 = 2**(n-1)
    o = m - 1
    p1 = 0
    for j in range(1,m):
        #print(j)
        p2 += 2**j
    for j in range(m,n-1):
        #print(j)
        p1+=2**j
    print(abs(p2-p1))