it = iter(input())
pointsA=0
pointsB=0
winPlace=11
flag=1
for i, j in zip(it, it):
    if i=='A':
        pointsA+=int(j)
    elif i=='B':
        pointsB+=int(j)
    
    if pointsA == pointsB and pointsA==10:
        flag=0
        #print("flag")        
    if flag:
        if pointsA>=winPlace:
            #print(pointsA)
            print("A")
            break
        if pointsB>=winPlace:
            #print(pointsB)
            print("B")
            break
    else:
        if pointsA >= (pointsB + 2):
            #print(pointsA)
            print("A")
            break
        elif pointsB >= (pointsA + 2):
            #print(pointsB)
            print("B")
            break
