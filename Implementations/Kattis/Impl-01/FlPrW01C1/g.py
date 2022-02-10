n, l = map(int, input().split())
li = list(map(int,input().split()))
s, c= 0, 0
for i in li:
    if ((i+s) <= l):
        s+=i
        c+=1
    else:
        print(c)
        break
else:
    print(c)