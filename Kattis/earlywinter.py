n , dm = map(int,input().split())
li = list(map(int, input().split()))
x = -1
for i in range(n):
    if int(li[i]) <= dm:
        x = i
        print("It hadn't snowed this early in %d years!"%x)
        break
else:
    print("It had never snowed this early!")