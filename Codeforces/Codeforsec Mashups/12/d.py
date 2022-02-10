za = [2**i for i in range(31)]
za2=[0]*31

su =0 
for i in range(31):
    su+=za[i]
    za2[i]=su
del za2[0]
for i in range(int(input())):
    n = int(input())
    for i in za2:
        if not(n%i):
            tem = n/i
            print(int(tem))
            break