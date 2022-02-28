n = int(input())
for i in range(n):
    lst = list(map(int, input().split()))
    k = lst[0]
    lst.pop(0)
    cnt = 0
    for i in range(len(lst)):
        