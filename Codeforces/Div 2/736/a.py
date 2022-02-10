

def SieveOfEratosthenes(n):
    
    prime = [True for i in range(n+1)]
     
    p = 2
    while(p * p <= n):
        if (prime[p] == True):
            for i in range(p * p, n + 1, p):
                prime[i] = False
        p += 1
 
    return prime

def listofprimes(n,prime):
    lii =[]
    for p in range(2, n):
        if prime[p]:
            lii.append(p)
    return lii


nums = []
ma = -1
for i in range(int(input())):
    t = int(input())
    if t>ma: 
            ma = t
    nums.append(t)
    
theprimes = SieveOfEratosthenes(ma)
for i in nums:
    pri = listofprimes(i-1,theprimes)
    #print(pri)
    m = len(pri)
    flag = False
    for j in range(1,m):
        tem = pri[j]*pri[j-1]
        if tem < i:
            dif = i - tem
            if dif < pri[j-1]:
                print(pri[j-1],pri[j])
                flag = True
                break
        else:
            break
    if flag:
        continue
    else:
        for k in pri:
            jj = 1
            while(True):
                te1 = (k**jj)
                te2 = (k**(jj+1))
                mo = i%te2
                if te2>i or te1>i:
                   break
                else: 
                    if mo < te1:
                        print(te1,te2)
                        flag = True
                        break
                    else:
                        jj+=1
            if flag:
                break