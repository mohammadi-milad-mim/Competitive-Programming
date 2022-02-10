import sys

dic = {}
for line in sys.stdin:
    tem = list(line.split())
    if len(tem)==3 and tem[0]=="define":
        if tem[2] in dic.keys():
            dic[tem[2]].append(int(tem[1]))
        else:
            dic[tem[2]]=[int(tem[1])]
            
    elif len(tem)==4 and tem[0]=="eval":
        if tem[1] in dic.keys() and tem[3] in dic.keys():
            x = dic[tem[1]][-1]
            y = dic[tem[3]][-1]
            if tem[2]=='<':
                if x < y: print("true")
                else: print("false")
            elif tem[2]=='>':
                if x > y: print("true")
                else: print("false")
            else:
                if x == y: print("true")
                else: print("false")
        else:
            print("undefined")