n , m = map(int, input().split())
for i in range(n):
    t = i+1
    if t%2:
        print("#"*m)
    elif t%4:
        print("."*(m-1),"#", sep='')
    else:
        print("#","."*(m-1),sep='')