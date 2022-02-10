for i in range(int(input())):
    li = list(map(int,input().split()))
    li.sort()
    dis=-1
    flag=-1
    if (li[1] == li[2]) and (li[0] == li[1]):
        print(0)
        continue
    elif li[1] ==li[0]:
        flag=1
    elif li[1] ==li[2]:
        flag=2
    else:
        flag=3

    if flag == 3:
        li[0]+=1
        li[2]-=1
    elif flag == 1:
        li[0]+=1
        li[1]+=1
        if li[1]==li[2]:
            dis = 0
        else:
            li[2]-=1
    elif flag==2:
        li[1]-=1
        li[2]-=1
        if li[1]==li[0]:
            dis = 0
        else:
            li[0]+=1
    if dis == 0:
        print(0)
    else:
        print((li[1]-li[0])+(li[2]-li[1])+(li[2]-li[0]))