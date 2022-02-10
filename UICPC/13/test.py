import datetime
ats = datetime.datetime.now()
def te(i,j):
    return i+j
a = datetime.datetime.now()
i,j=0,1
t = 10**9
print(t)
for i in range(t):
    i += j
    j/=2
    
ate = datetime.datetime.now()

print ((ate-ats).total_seconds())
