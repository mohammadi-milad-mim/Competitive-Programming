n = int(input())
if n%2:
    n+=2
    print(int((n-1)*(n+1)/4))
else:
    n=n//2+1
    print(n*n)