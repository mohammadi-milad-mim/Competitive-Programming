n = int(input())
hf = n//2
count = 0
md = 1000000007
if (n%2):
    hf +=1
    for a in range(1,hf):
        for b in range(a,hf):
            c = n - a - b
            if (a+b>=hf) and (c>=b):
                count+=1   
else:
    for a in range(1,hf):
        for b in range(a,hf):
            c = n - a - b
            if (a+b>hf) and (c>=b):
                count+=1
print(count%1000000007)