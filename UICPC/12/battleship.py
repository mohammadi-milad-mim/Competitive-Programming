for i in range(int(input())):
    w,h,n = map(int,input().split())
    p1 = []
    sNumP1 = 0
    sNumP2 = 0
    p2 = []
    for i in range(h-1,-1,-1):
        lin = list(input())
        for j in range(w):
            if lin[j]=='#':
                p1.append([j,i])
                sNumP1+=1
    for i in range(h-1,-1,-1):
        lin = list(input())
        for j in range(w):
            if lin[j]=='#':
                p2.append([j,i])
                sNumP2+=1
    shots = []
    for i in range(n):
        x,y = map(int,input().split())
        tem = [x,y]
        shots.append(tem)
    
    turn=1
    p1f = False
    p2f = False
    '''print(p1)
    print(p2)
    print(shots)'''
    for j in range(n):
        #print(j)
        i=shots[j]
        #print(i)
        if turn%2:
            if i in p2:
                p2.remove(i)
                #print(p2)
                le2 = len(p2)
                if not(le2):
                    p1f=True
                    break
            else:
                turn+=1
                continue
        else:
            if i in p1:
                p1.remove(i)
                #print(p1)
                le1 = len(p1)
                if not(le1):
                    p2f=True
                    break
            else:
                turn+=1
                continue
    j+=1
    #print('this is j    ',j)
    p2ff = False
    p1ff = False
    if p1f:
        while(j<n):
            i=shots[j]
            if i in p1:
                p1.remove(i)
                le1 = len(p1)
                if not(le1):
                    p2ff=True
                    break
                j+=1
            else: break
        if p2ff:
            print("draw")
        else:
            print("player one wins")
    elif p2f:
        print("player two wins")
    else:
        print("draw")