s = list(input())
n = len(s)
nn = n//3
s1 = s[:nn]
s2 = s[nn:2*nn]
s3= s[2*nn:3*nn]
'''print(s)
print(s1)
print(s2)
print(s3)'''
res = ""
for i in range(nn):
    if s1[i]==s2[i]:
        res+=s1[i]
    elif s1[i]==s3[i]:
        res+=s1[i]
    elif s2[i]==s3[i]:
        res+=s2[i]
    else:
        print("ERROR")
print(res)