import math
from collections import Counter


numbers = int(input())
seq = list(map(int, input().split()))
MAXN = max(seq)+1

spf = [0 for i in range(MAXN)]

def sieve():
	spf[1] = 1
	for i in range(2, MAXN):
		spf[i] = i

	for i in range(4, MAXN, 2):
		spf[i] = 2

	for i in range(3, math.ceil(math.sqrt(MAXN))):
		
		if (spf[i] == i):
			
			for j in range(i * i, MAXN, i):

				if (spf[j] == j):
					spf[j] = i

def getFactorization(x):
	ret = list()
	while (x != 1):
		ret.append(spf[x])
		x = x // spf[x]

	return ret

def CountFrequency(my_list):
    freq = {}
    for item in my_list:
        if (item in freq):
            freq[item] += 1
        else:
            freq[item] = 1
            
    return freq

sieve()
#print(spf)
p = []

for i in range(numbers):
    p.append(CountFrequency(getFactorization(seq[i])))
    #print(p[i])

count = Counter()
for y in p:
  count += Counter(y)
#print(count)

validlist = []
thenum=1
for i in count.items():
    if i[1]>=numbers:
        j = list(i)
        j[1]=j[1]//numbers
        thenum*=(j[0]**j[1])
        validlist.append(j)

print(thenum, end=" ")
#print(validlist)

steps = 0
for i in validlist:
    pri = i[0]
    con = i[1]
    for j in p:
        #print("this is j:      ",j)
        #print("this is pri:     ",pri)
        if pri in j:
            #print("true")
            dif = con - j[pri]
            #print(con)
            #print(dif)
            if dif > 0:
                steps+=(dif)
        else:
            steps+=con

print(steps)