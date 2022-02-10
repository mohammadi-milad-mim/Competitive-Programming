def inra(i,j):
    if i<0 or i>=5 or j<0 or j>=5:
        return 0
    else:
        return 1

def the(i,j):
    t = []
    ii = i-2
    jj = j+1
    if inra(ii,jj): t.append([ii,jj])
    jj = j-1
    if inra(ii,jj): t.append([ii,jj])
    ii = i+2
    jj= j+1
    if inra(ii,jj): t.append([ii,jj])
    jj = j-1
    if inra(ii,jj): t.append([ii,jj])
    jj=j-2
    ii = i+1
    if inra(ii,jj): t.append([ii,jj])
    ii = i-1
    if inra(ii,jj): t.append([ii,jj])
    jj = j+2
    ii=i+1
    if inra(ii,jj): t.append([ii,jj])
    ii=i-1
    if inra(ii,jj): t.append([ii,jj])
    return t

rokh = []
pos = []
c=0
for i in range(5):
    li = list(input())
    for j in range(5):
        if li[j]=='k':
            c+=1
            rokh.append([i,j])
            tt = the(i,j)
            if len(tt):
                for tem in tt:
                    if tem in rokh:
                        print("invalid")
                        exit()
                    else:
                        pos.append(tem)
if c!=9:
    print("invalid")
else:
    for tem in pos:
        if tem in rokh:
            print("invalid")
            break
    else:
        print("valid")
                        