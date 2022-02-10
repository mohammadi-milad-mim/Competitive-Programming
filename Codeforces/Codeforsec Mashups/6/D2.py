def LCSubStr(X, Y, m, n):
    LCSuff = [[0 for k in range(n+1)] for l in range(m+1)]
 
    result = 0

    for i in range(m + 1):
        for j in range(n + 1):
            if (i == 0 or j == 0):
                LCSuff[i][j] = 0
            elif (X[i-1] == Y[j-1]):
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1
                result = max(result, LCSuff[i][j])
            else:
                LCSuff[i][j] = 0
    return result


for t in range(int(input())):
    s1 = list(input())
    s2= list (input())
    m = len(s1)
    n = len(s2)
    if n+m == 2:
        if s1[0] == s2[0]:
            print(0)
            continue
        else:
            print(2)
            continue
    
    ma = LCSubStr(s1, s2, m, n)
    print((n+m)-(2*ma))