mesures = [[0,'th',(1/1000),-1,'thou'],[1,'in',(1/12),1000,'inch'],[2,'ft',(1/3),12,'foot'], [3,'yd',(1/22),3,'yard'],[4,'ch',(1/10),22,'chain'],[5,'fur',(1/8),10,'furlong'], [6,'mi',(1/3),8,'mile'], [7,'lea',-1,3,'league']]
inpu = list(input().split())
num = int(inpu[0])
start = inpu[1]
ns = -1
ne = -1
end = inpu[3]
for i in mesures:
    if i[1]==start or i[4]==start:
        ns = i[0]
    elif i[1]==end or i[4]==end:
        ne = i[0]
#print(ne,ns)
if ns == ne:
    print(num)
elif ne > ns:
    for i in range(ns,ne):
        num*=mesures[i][2]
    print(num)
else:
    for i in range(ns,ne,-1):
        num*=mesures[i][3]
    print(num)