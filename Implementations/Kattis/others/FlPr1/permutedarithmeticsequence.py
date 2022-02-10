for i in range(int(input())):
    li = list(map(int,input().split()))
    n = li[0]
    the = li[1:]
    dif = the[1]-the[0]
    for i in range(n-1):
        te = the[i+1] - the[i]
        if  te != dif:
            break
    else:
        print("arithmetic")
        continue
    the.sort()
    dif = the[1]-the[0]
    for i in range(n-1):
        te = the[i+1] - the[i]
        if  te != dif:
            print("non-arithmetic")
            break
    else:
        print("permuted arithmetic")
        continue