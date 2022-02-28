n , m = map(int, input().split())
lst = list(map(int, input().split()))
sm = 0
index = 0
for i in range(n):
    if sm+lst[i] > m:   
        index = i
    else:
        sm += lst[i]
print((n-index)-1)
