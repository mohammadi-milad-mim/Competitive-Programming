srti = list(input().split())
#print(srti)
punc = [33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,58,59,60,61,62,63,64,91,92,93,94,95,96,123,124,125,126]
nonPunc=[32,48,49,50,51,52,53,54,55,56,57,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,97,98,99,100,101,102,103,104,105,106,107,108,110,111,112,113,114,115,116,118,119,120,121,122]
code=[]
full_m_code=""
for i in srti:
    if (('u' in i) or ('m' in i) ):
        #print(i)
        flag=1
        for j in i:
            if ord(j) in nonPunc:
                flag=0
                break
        if (flag):
            for j in i:
                if ord(j) in punc:
                    #print(j)
                    i = i.replace(j,"")
            #code.append(i)
            full_m_code+=i
            #print(i)
#print(full_m_code)

theCode = full_m_code.replace('u','1')
theCode = theCode.replace('m','0')
#print(theCode)    
#print (theCode)
slist=[ theCode[i:i+7] for i in range(0, len(theCode), 7) ]

for h in slist:
    iH = int(h,2)
    if iH >= 32 and iH <= 126:
        print(chr(iH), end="")
