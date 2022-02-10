import sys
vo = ['a','e','i','o','u','y']
for line in sys.stdin:
    li = list(line.split())
    chap = []
    for i in li:
        if i[0] in vo:
            tem = i+'yay'
            chap.append(tem)
        else:
            for j in range(1,len(i)):
                if i[j] in vo:
                    fi = i[:j]
                    tem = i[j:]+fi+'ay'
                    chap.append(tem)
                    break
    print(*chap,sep=" ")