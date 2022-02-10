a = list(input())
n = len(a)
for i in range(1,n):
    if a[i]=='s' and a[i-1]=='s':
        print("hiss")
        break
else:
    print("no hiss")