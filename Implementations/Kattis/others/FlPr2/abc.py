num= list(map(int,input().split()))
num.sort()
s = list(input())
for i in range(3):
    if s[i]=='A':
        print(num[0],end=" ")
    elif s[i]=='B':
        print(num[1],end=" ")
    elif s[i]=='C':
        print(num[2],end=" ")