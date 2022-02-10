n = int(input())
s = 0
for i in range(n):
    x = int(input())
    num = x // 10
    po = x %10
    s+= (num**po)
print(s)