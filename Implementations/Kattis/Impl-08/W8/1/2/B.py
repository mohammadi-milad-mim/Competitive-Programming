from decimal import Decimal

T = int(input())
for i in range(T):
    print("Recipe # ",i+1,sep='')
    R,P,D = map(int,input().split())
    scale = D/P
    main = 0
    li = []
    for j in range(R):
        name,we,per = map(str,input().split())
        we = float(we)
        per = float(per)
        if per == 100.0:
            main = we*scale
        li.append([name,we,per])
    for j in li:
        if j[2]==100.0:
            print(j[0],round(main,1))
        else:
            res = j[2] * main / 100.0
            print(j[0],round(res,1))
    print("----------------------------------------")