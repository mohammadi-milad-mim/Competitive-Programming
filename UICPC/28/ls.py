import re
import random
rex = list(input())
frex = ""
for i in rex:
    if (i=='*'):
        frex+='.*'
    elif (i=='.'):
        frex+='[.]'
    else:
        frex+=i
n = int(input())
leng = len(frex)
res = []
for i in range(n):
    txt = input()
    if leng<20:
        obj = re.fullmatch(frex,txt)
        if obj!=None:
            #res.append(obj.string)
            print(obj.string)
    else:
        rd =random.choice([True,False,False])
        if rd==True: 
            print(txt)
#print(res)
#print(*res,sep="\n")