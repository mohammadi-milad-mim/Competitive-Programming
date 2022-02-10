n = list(map(int, input().split()))
MAXI = n[1]
MINI = n[0]
dp = [-1]*(MAXI+1)
if n[1] < 10:
    if n[2] <= MAXI and n[2]>=MINI:
        print(1)
        print(n[2])
        exit()
    else:
        print("ERROR")
        exit()
else:
    for i in range(10):
        dp[i]=i
    cmin = MAXI + 1
    count = 0

    def findit (dp, m, li):
        #print(dp)
        print("THIS IS m:      ",m)
        print("THIS IS C:", li[2])
        if dp[m]==-2 or li[3]==-2:
            li[3]=-2
            return li
        
        elif dp[m]!=-1:
            li[2]+= dp[m]
            
            print("THIS IS NEXT c:       ",li[2])
            if li[2] == li[0]:
                if m>=MINI:
                    li[1]+=1
                    if m < li[4]:
                        li[4] = m
                return li
            elif li[2] > li[0]:
                li[3]=-2
                return li
            else:
                return li
            
        elif dp[m]==-1:
            yekan = m % 10
            li[2]+=yekan
            something = findit(dp, m//10,li)
            if something[3] == -2:
                dp[m]=-2
            else:
                dp[m]=li[2]+something[2]
            return li
                
    LI=[n[2],0,0,-1,cmin]
    for i in range(MAXI,MINI-1,-1):
        #print(i)
        #print(LI)
        findit(dp,i,LI)
        LI[3],LI[2]= -1, 0
    
    print("ANSWER!!!!!!!!!!!!")
    print(LI[1])
    print(LI[4])
            