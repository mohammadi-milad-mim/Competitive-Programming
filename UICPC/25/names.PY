def pali(li):
    nn = len(li)
    end = nn-1
    count = 0
    if (nn%2):
        for i in range(nn//2):
            if li[i]!=li[end-i]:
                count+=1
    else:
        for i in range(nn//2):
            if li[i]!=li[end-i]:
                count+=1
    return count
st = list(input())
n = len(st)

mi = 200
for j in range(n//2):
    nst=st[j:]
    #print(nst)
    mi = min(mi,pali(nst)+j)
if n==1:
    print(0)
else:
    print(mi)