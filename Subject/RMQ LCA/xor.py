k = 4
li = [1,2,5,7]
for i in range(4,17):
    t = li[i-1]^li[i-2]^li[i-3]^li[i-4]
    li.append(t)
print(li)