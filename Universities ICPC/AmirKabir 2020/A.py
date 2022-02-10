a,b = map(int,input().split())
s = 0
if (b%2==0):
    s+=0
    if (a%2==0):
        s+=0
    else:
        s+=b
else:
    s+=a
    if (a%2==0):
        s+=0
    else:
        s-=b
print(s)