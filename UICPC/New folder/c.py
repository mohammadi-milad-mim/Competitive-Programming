pos = []
neg = []
alls = []
txt = list(input())
leng = len(txt)
i = 0
num = 0
c=-1
sign = 1
lg = 0
while(i<leng):
    if (txt[i]=='+'):
        if (c==-1):
            sign = 1
        else:
            if (sign ==1):
                pos.append(num)
            else:
                neg.append(num*-1)
            alls.append(num*sign)
        sign=+1
        lg=0
        c+=1
        num=0   
    elif (txt[i]=='-'):
        if (c==-1):
            sign = -1
        else:
            if (sign ==1):
                pos.append(num)
            else:
                neg.append(num*-1)
            alls.append(num*sign)
        sign=-1
        lg=0
        c+=1
        num=0   
    else:
        num*=10
        num+=int(txt[i])
        #num+=(int(txt[i]))*(10**lg)
        lg+=1
    i+=1
if (sign ==1):
    pos.append(num)
else:
    neg.append(num*-1)
alls.append(num*sign)
neg.sort()
neg.reverse()
pos.sort()
pos.reverse()


#print(neg)
#print(pos)
#print(alls)

finaltxt = ""
res=0

n_neg = len(neg)
n_pos = len(pos)

if (n_neg==n_pos):
    for i in range(n_neg):
        tneg = neg[i]
        tpos = pos[i]
        res += tneg + tpos
        finaltxt += '+'+str(tpos)+str(tneg)
        
    finaltxt+='='+str(res)
    print(finaltxt)
    
elif (n_pos> n_neg):
    for i in range(n_neg):
        tneg = neg[i]
        tpos = pos[i]
        res += tneg + tpos
        finaltxt += '+'+str(tpos)+str(tneg)
    
    if (pos[n_neg]>res):
        pos[n_neg]*=-1
        res+=pos[n_neg]
        finaltxt += str(pos[n_neg])
    else:
        res+=pos[n_neg]
        finaltxt += '+'+str(pos[n_neg])
        
    for i in range(n_neg+1,n_pos):
        tpos = pos[i]
        res+=tpos
        finaltxt += '+'+str(tpos)
    
    finaltxt+='='+str(res)
    print(finaltxt)

else:
    for i in range(n_pos):
        tneg = neg[i]
        tpos = pos[i]
        res += tneg + tpos
        finaltxt += '+'+str(tpos)+str(tneg)
    
    flag=True
    if (res<0):
        neg[-1]*=-1
        res+=neg[-1]
        finaltxt += '+'+str(neg[-1])
        flag=False
        
    for i in range(n_pos,n_neg-1):
        tneg = neg[i]
        res+=tneg
        finaltxt += str(tneg)
        
    if (flag):
        tneg = neg[i]
        res+=tneg
        finaltxt += str(tneg)
        
    
    finaltxt+='='+str(res)
    print(finaltxt)
    