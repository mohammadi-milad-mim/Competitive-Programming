first = list(input())
sec = list(input())
third = list(input())
first.sort()
sec.sort()
third.sort()
i = 0
while(((len(third))!=0 ) and (i < len(third))):
    print(third[i])
    print(third)
    if third[i] in first:
        third.pop(i)
    elif i in sec:
        third.pop(i)
    else:
        print("NO")
        break
else:
    if len(third):
        print("NO")
    else:
        print("YES")
