s = list(input())
n = len(s)
if (n<=3): print(*s,sep='')
else:
    mi = 'z'*50
    for i in range(1,n-1):
        for j in range(i+1,n):
            mi = min(mi,''.join(s[:i])[::-1] + ''.join(s[i:j])[::-1] + ''.join(s[j:])[::-1])
    print(*mi,sep='')