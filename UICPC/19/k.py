s = input()
li = list(s)
l = len(s)
ll = l//2 + 1
for i in range(1,ll):
    if not(l%i):
        m = li[:i]
        for j in range(0,l-i+1,i):
            if li[j:j+i] == m:
                m = m[-1:] + m[:-1] 
                continue
            else:
                break
        else:
            print(i)
            break
else:
    print(l)