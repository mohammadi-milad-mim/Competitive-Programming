kit = int(input())
tre = {}
while(True):
    temp = list(map(int, input().split()))
    if temp[0] == -1: break
    tre.update({temp[0]: temp[1:]})
#print(tre)
path=[]
path.append(kit)
while(True):
    for i in tre.items():
        #print(i[1])
        if kit in i[1]:
            path.append(i[0])
            kit = i[0]
            del tre[i[0]]
            break
    else:
        print(*path,sep=' ')
        break
    
    