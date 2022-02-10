for i in range(int(input())):
    n = int(input())
    t = []
    c = 0
    for j in range(n):
        tem = input()
        if tem in t:
            continue
        else:
            t.append(tem)
            c+=1
    print(c)