for i in range(int(input())):
    n = int(input())
    s=list(map(int, input().split()))
    s.sort()
    res = 1004
    for j in range(n-1):
        res = min(res,s[j+1]-s[j])
    print(res)