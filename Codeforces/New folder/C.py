for i in range(int(input())):
    n,a,b = map(int,input().split())
    if (a+b+2 > n or abs(a-b)>1):
        print(-1)
    else:
        lis = []
        if (a==b):
            if (a+b+2==n):
                hf = n//2
                for i in range(1,hf+1):
                    lis.append(i)
                    lis.append(i+hf)
                print(*lis,sep='')
            else:
                nn = a+b+2
                hf = nn//2
                for i in range(1,hf+1):
                    lis.append(i)
                    lis.append(i+hf)
                for i in range(n-nn+1,n+1):
                    lis.append(i)
                print(*lis,sep='')
        else:
            if (a>b):
                if (a+b+2==n):
                    c=1
                    for i in range(a):
                        lis.append(c)
                        lis.append(n-i)
                        c+=1
                    lis.append(c)
                    print(*lis,sep='')
                else:
                    c=n-a
                    nn = a+b+2
                    for i in range(a):
                        lis.append(c)
                        lis.append(n-i)
                        c+=1
                    for i in range(n-nn+1,n+1):
                        lis.append(c)
                        c+=1
                
            
                