li =list(input().split())
dp = []
mi = int(li[0])
while (mi!=-1):
    if len(dp):
        for i in dp:
            if li[1]==i[0]:
                if li[2]=="right":
                    i[1]=1
                    i[3]=mi
                    break
                else:
                    i[2]+=1
                    break
        else:
            if li[2]=="right":
                dp.append([li[1],1,0,mi])
            else:
                dp.append([li[1],0,1,0])
    else:
        if li[2]=="right":
            dp.append([li[1],1,0,mi])
        else:
            dp.append([li[1],0,1,0])
    li = list(input().split())
    mi = int(li[0])
time = 0
c = 0
for i in dp:
    if i[1]:
        c+=1
        time+=i[3]+(i[2]*20)
print(c,time,sep=" ")  