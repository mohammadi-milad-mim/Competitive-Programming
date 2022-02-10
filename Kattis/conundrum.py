s = list(input())
c=0
for i in range(0,len(s),3):
    if s[i]!='P':
        c+=1
    if s[i+1]!='E':
        c+=1
    if s[i+2]!='R':
        c+=1
print(c)