s=list(input())
t=list(input())
ii=0
i=0
while(i<len(s)):
    if s[i]==t[ii]:
        del t[ii]
        i+=1
    else:
        ii+=1
#print(t)
se = set(t)
print(*se,sep="")