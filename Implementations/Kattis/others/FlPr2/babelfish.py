import sys
dic = {}
flag = True
for line in sys.stdin:
    if line != '\n' and flag:
        te = list(line.split())
        dic[te[1]]=te[0]
    elif line != '\n' and not(flag):
        a = line.split()
        aa = a[0]
        if aa in dic.keys():
            print(dic[aa])
        else:
            print("eh")
    else:
        flag=False