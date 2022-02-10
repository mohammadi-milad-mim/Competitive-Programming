n = int(input())
#p_i, t_i, if switch t_i = -1, index = id-1
lamps = []
for i in range(n):
    temp = list(input().split())
    if (temp[0]=="SWITCH"):
        lamps.append([int(temp[1]),-1,[]])
    elif (temp[0]=="SENSOR"):
        lamps.append([int(temp[1]),int(temp[2]),[]])

costs = []
m = int(input())

for i in range(m):
    temp = list(map(int,input().split()))
    costs.append(temp)

def timetosec(day,time):
    sec = 0
    hour = int(time[0])*10 + int(time[1])
    sec += hour*3600
    mi = int(time[3])*10 + int(time[4])
    sec+=mi*60
    se = int(time[6])*10 + int(time[7])
    sec+=se
    day-=1
    se += day*86400
    return se

k = int(input())
for i in range(k):
    temp = list(input().split())
    se = timetosec(int(temp[1]),temp[2])
    lamps[int(temp[0])-1][2].append(se)

#print(lamps)

raw = 0

for l in lamps:
    if (l[1]==-1):
        count = len(l[2])
        if (count%2):
            l[2].append(timetosec(31,"23:59:59"))
            count+=1
        for i in range(0,count,2):
            dur = l[2][i+1]-l[2][i]
            raw += (dur * l[0])

#print(raw)
ful = 0
for c in range(len(costs)):
    if raw >= costs[c][0]:
        ful = costs[c][1]*raw
        break
else:
    ful = costs[0][1]*raw
print(ful)
#def duration(time1, time2):
    
    
