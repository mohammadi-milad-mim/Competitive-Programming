li1=list(map(int,input().split()))
li2=list(map(int,input().split()))
arr1 = li1 + li1
arr2 = li2 + li2
for i in range(0,7):
    for j in range(0,7):
        n11, n12, n13= arr1[i],arr1[i+1],arr1[i+2]
        n21, n22, n23 = arr2[j],arr2[j+1],arr2[j+2]
        res = ((n11+n21)%10)*100+((n12+n22)%10)*10+((n13+n23)%10)
        #print(res)
        if res%6 == 0:
            print("Boro joloo :)")
            exit()
print("Gir oftadi :(")