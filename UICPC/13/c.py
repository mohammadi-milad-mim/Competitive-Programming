
def inrange(i,j):
    if (i>=0) and (i<m) and (j>=0) and (j<n):
        return 1
    else:
        return 0

m,n = map(int,input().split())
dp=[]
for i in range(m):
    dp.append(list(map(int,input().split())))
x,y = map(int,input().split())
x-=1
y-=1
cars = []
visited = []
flag = True
#print(dp[0])
#print(dp[0][0])
while(flag):
    pflag = True
    if inrange(x,y+1):
        if dp[x][y+1]==dp[x][y]:
            pflag=False
            cars.append(dp[x][y])
            if inrange(x,y+2):
                if dp[x][y+2] == -1:
                    for i in range(len(cars)-1,-1,-1):
                        print(cars[i],end=' ')
                    exit()
                elif dp[x][y+2] == -2:
                    print('impossible')
                    exit()
                else:
                    if [x,y+2] in visited:
                        print("impossible")
                        exit()
                    else:
                        visited.append([x,y+2])
                        y+=2
                    
            else:
                print("impossible")
                exit()
    
    if inrange(x,y-1) and pflag:
        if dp[x][y-1]==dp[x][y]:
            pflag=False
            cars.append(dp[x][y])
            if inrange(x,y-2):
                if dp[x][y-2] == -1:
                    for i in range(len(cars)-1,-1,-1):
                        print(cars[i],end=' ')
                    exit()
                elif dp[x][y-2] == -2:
                    print('impossible')
                    exit()
                else:
                    if [x,y-2] in visited:
                        print("impossible")
                        exit()
                    else:
                        visited.append([x,y-2])
                        y-=2
            else:
                print("impossible")
                exit()
        
    if inrange(x+1,y)and pflag:
        if dp[x+1][y]==dp[x][y]:
            pflag=False
            cars.append(dp[x][y])
            if inrange(x+2,y):
                if dp[x+2][y] == -1:
                    for i in range(len(cars)-1,-1,-1):
                        print(cars[i],end=' ')
                    exit()
                elif dp[x+2][y] == -2:
                    print('impossible')
                    exit()
                else:
                    if [x+2,y] in visited:
                        print("impossible")
                        exit()
                    else:
                        visited.append([x+2,y])
                        x+=2
            else:
                print("impossible")
                exit()
            
    
    if inrange(x-1,y) and pflag:
        if dp[x-1][y]==dp[x][y]:
            pflag=False
            cars.append(dp[x][y])
            if inrange(x-2,y):
                if dp[x-2][y] == -1:
                    for i in range(len(cars)-1,-1,-1):
                        print(cars[i],end=' ')
                    exit()
                elif dp[x-2][y] == -2:
                    print('impossible')
                    exit()
                else:
                    if [x-2,y] in visited:
                        print("impossible")
                        exit()
                    else:
                        visited.append([x-2,y])
                        x-=2
            else:
                print("impossible")
                exit()
    
    if pflag:
        flag = False
        print("impossible")
        exit()