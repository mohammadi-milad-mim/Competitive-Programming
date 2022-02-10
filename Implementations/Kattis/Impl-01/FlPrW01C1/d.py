def toint(a):
    return ord(a)-65

def tochar(i):
    return chr(((i%26)+65))

s = list(input())
n = len(s)
mid = n//2
s1 = s[:mid]
s2 = s[mid:]

ss1, ss2 = 0,0
for i in s1:
    ss1+=toint(i)
fs1, fs2 = '',''
for i in s1:
    fs1+=tochar(toint(i)+ss1)

for i in s2:
    ss2+=toint(i)
for i in s2:
    fs2+=tochar(toint(i)+ss2)

final=''
for i in range(mid):
    final+=tochar(toint(fs1[i])+toint(fs2[i]))

print(final)
    