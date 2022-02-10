a = list(input())
b = list(input())
a[0]= ord(a[0])-96
b[0]= ord(b[0])-96
a[1]= int(a[1])
b[1]= int(b[1])

if a[0] > b[0]:

    if a[1] > b[1]:
        x = a[0]-b[0]
        y = a[1]-b[1]
        if x > y:
            print(x)
            for i in range(y): print("LD")
            for i in range(x-y): print("L")
        elif x < y:
            print(y)
            for i in range(x): print("LD")
            for i in range(y-x): print("D")
        else:
            print(x)
            for i in range(x): print("LD")

    elif a[1] < b[1]:
        x = a[0]-b[0]
        y = b[1]-a[1]
        if x > y:
            print(x)
            for i in range(y): print("LU")
            for i in range(x-y): print("L")
        elif x < y:
            print(y)
            for i in range(x): print("LU")
            for i in range(y-x): print("U")
        else:
            print(x)
            for i in range(x): print("LU")

    
    else:
        x = a[0]-b[0]
        print(x)
        for i in range(x): print("L")



elif a[0] < b[0]:

    if a[1] > b[1]:
        x = b[0]-a[0]
        y = a[1]-b[1]
        if x > y:
            print(x)
            for i in range(y): print("RD")
            for i in range(x-y): print("R")
        elif x < y:
            print(y)
            for i in range(x): print("RD")
            for i in range(y-x): print("D")
        else:
            print(x)
            for i in range(x): print("RD")

    elif a[1] < b[1]:
        x = b[0]-a[0]
        y = b[1]-a[1]
        if x > y:
            print(x)
            for i in range(y): print("RU")
            for i in range(x-y): print("R")
        elif x < y:
            print(y)
            for i in range(x): print("RU")
            for i in range(y-x): print("U")
        else:
            print(x)
            for i in range(x): print("RU")

    
    else:
        x = b[0]-a[0]
        print(x)
        for i in range(x): print("R")


else:
    if a[1] > b[1]:
        x = a[1]-b[1]
        print(x)
        for i in range(x): print("D")

    elif a[1] < b[1]:
        x = b[1]-a[1]
        print(x)
        for i in range(x): print("U")
    else:
        print(0)
    

