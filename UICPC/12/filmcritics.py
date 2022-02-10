n,m,k = map(int, input().split())
aa = list(map(int, input().split()))
a = []
for i in range(n):
    a.append([aa[i], i+1])
a.sort()
if not(k%m):
    t = int(k/m)
    if t < 1:
        print("impossible")
        exit()
    se =n - t
    if n == 1:
        if t == 1:
            print(1)
            exit()
        else:
            print("impossible")
            exit()
    elif se < 0:
        print("impossible")
        exit()
    #print(se)
    first = a[0:se]
    first.reverse()
    #print(first)
    sec = a[se:n]
    #print(sec)
    
    jj,kk= 0,0
    result = [sec[0][1]]
    ii = 1
    avg = m
    for i in range(1,n):
        #print(i)
        if ii != t and sec[ii][0] >= (avg / i):
            result.append(sec[ii][1])
            ii +=1
            avg += m
        elif jj != se and first[jj][0] < (avg / i):
            result.append(first[jj][1])
            jj+=1
        else:
            print("impossible")
            break
    else:
        print(*result,sep=" ")
else:
    print("impossible")
    
