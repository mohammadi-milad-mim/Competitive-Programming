a = input()
b = input()

#print(a)
#print(b)
aSw= a.swapcase()
#print(aSw)


if (a==b):
    print("Yes")
elif (b==aSw):
    print("Yes")
elif ((b in a) and (len(b)+1==len(a))):
    flag=1
    fflag=1
    preA=[]
    for i in range(10):
        preA.append(str(i)+b)
        #print(preA[i])
        if (preA[i]==a):
            flag=0
            print("Yes")
            break
    if flag:
        postA=[]
        for i in range(10):
            postA.append(b+str(i))
            #print(postA[i])
            if (postA[i]==a):
                fflag=0
                print("Yes")
                break
        if fflag:
            print("No")
else:
    print("No")
