g = list(input())
ha = list(list(input().split()))
for i in ha:
    t = list(i)
    #print(t)
    if t[0]==g[0] or t[1]==g[1]:
        print("YES")
        break
else:
    print("NO")