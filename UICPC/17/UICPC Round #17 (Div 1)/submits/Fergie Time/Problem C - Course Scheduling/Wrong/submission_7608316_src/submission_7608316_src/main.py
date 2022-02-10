from collections import defaultdict,OrderedDict
dict2 = defaultdict(set)
n=int(input())
while n:
    n-=1
    temp = list(input().split())
    dict2[temp[2]].add(temp[0]+temp[1])


dict2= OrderedDict(sorted(dict2.items(), key=lambda item: len(item[1]), reverse=True))
for item in dict2:
    print(item,len(dict2[item]))
