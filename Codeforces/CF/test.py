c=0
for i in range(0,10**5+1,2):
    t = i//2
    c+=t
c*=100
print(c/10**9)