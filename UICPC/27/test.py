n = 100000
res = 0
for i in range(0,n):
    for j in range(i+1,n):
        for k in range(j+1,n):
            res+=1
print(res)