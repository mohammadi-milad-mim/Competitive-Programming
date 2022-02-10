j , ma = -1 , -1
for i in range(5):
    li = list(map(int, input().split()))
    if sum(li) > ma: j, ma = i, sum(li)
print(j+1, ma)