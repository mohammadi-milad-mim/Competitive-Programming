n = int(input())
c = 0
for i in range(n):
    inpu = list(input())
    for j in range(1,len(inpu)):
        if inpu[j]=='D' and inpu[j-1]=='C':
            break
    else:
        c+=1
print(c)