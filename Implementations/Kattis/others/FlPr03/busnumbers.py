n = int(input())
li = list(map(int,input().split()))
li.sort()
fl = True
if len(li)==1:
    print(li[0])
elif len(li)==2:
    print(li[0],li[1],sep=' ',end=' ')
else:
    for i in range(n-1):
        if li[i]==(li[i+1]-1) and fl:
            fl = False
            c=0
            s = li[i]
            if i==n-2:
                print(li[i],li[i+1],sep=' ',end=' ')
        elif li[i]==(li[i+1]-1) and not(fl):
            c+=1
            if i==n-2:
                e=li[i+1]
                print(s,'-',e,sep='',end=' ')
            continue
        elif li[i]!=(li[i+1]-1) and not(fl):
            fl = True
            e = li[i]
            if c>=1:
                print(s,'-',e,sep='',end=' ')
            else:
                print(s,e,sep=' ',end=' ')
            if i==n-2:
                print(li[i+1],end=' ')
        else:
            fl = True
            print(li[i],end=' ')
            if i==n-2:
                print(li[i+1],end=' ')