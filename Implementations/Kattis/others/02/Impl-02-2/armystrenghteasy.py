for i in range(int(input())):
    input()
    Ng,Nm = map(int,input().split())
    g=list(map(int,input().split()))
    m=list(map(int,input().split()))
    g.sort()
    m.sort()
    gg,mm=0,0
    while (gg<Ng and mm<Nm):
        if (m[mm]<=g[gg]):
            mm+=1
        else:
            gg+=1
    if (gg==Ng):
        print("MechaGodzilla")
    elif (mm==Nm):
        print("Godzilla")
    else:
        print("uncertain")