n = int(input())
while(n):
    fli = []
    li = []
    for i in range(n):
        te = input()
        li.append(te)
        tem = list(te)
        fli.append([tem[0],tem[1],i,te])
    fli.sort(key=lambda seq: (ord(seq[0]), ord(seq[1]),seq[2]))
    for t in fli:
        print(t[3])
    print('\n')
    n = int(input())
