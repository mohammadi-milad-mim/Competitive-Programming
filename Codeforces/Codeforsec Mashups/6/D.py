for t in range(int(input())):
    s1 = list(input())
    s2= list (input())
    n = len(s1)
    m = len(s2)
    if n+m == 2: 
        print(0)
        break
    dp = [[0]*(n+1)]*(m+1)
    for i in range(n-1,-1,-1):
        for j in range(m-1,-1,-1):
            if s1[i] == s2[j]:
                dp[j][i] = dp[j + 1][i + 1] + 1
    ma = max(map(max, dp))
    print(ma)
    print((n+m) - (2*ma))