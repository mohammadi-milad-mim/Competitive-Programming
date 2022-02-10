n = int(input())
li = []
for i in range(n):
    li.append(int(input()))
li.sort()

def tabe(li,lif,ls,i,c):
    if c+li[i]==1000:
        lif[i]=1000
        ls[0],ls[1]=1000,1000
        
    if c+li[i]>1000:
        if c+li[i]<ls[1]:
            ls[1] = c+li[i]
            lif[i]=1
            return ls
    else  
    