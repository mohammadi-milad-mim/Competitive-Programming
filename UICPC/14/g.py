import math

c,p = map(int,input().split())
full = []
allv = 0
majo = math.ceil(allv/2)
for i in range(p):
    full.append(list(map(int,input().split())))
    allv += full[-1][0]

votes = dict.fromkeys(range(1,c+1),0)
eli = []
for j in range(1,c+1):
    mi = -1
    cmi = 0
    limi = []
    ma = p+1
    lima = []
    cma = 0
    for i in range(p):
        #print(full[i][j])
        votes[full[i][j]]+=(full[i][0])
        if votes[full[i][j]]<mi:
            limi = [full[i][j]]
            mi = votes[full[i][j]]
        elif votes[full[i][j]]==mi:
            limi.append(full[i][j])
        
        if votes[full[i][j]]>ma:
            lima = [full[i][j]]
            ma = votes[full[i][j]]
        elif votes[full[i][j]]==ma:
            lima.append(full[i][j])
        
    if cma == 1 and ma >=majo:
        print(lima[0])
        exit()
    for tt in range(cmi):
        votes[limi[tt]]==-1