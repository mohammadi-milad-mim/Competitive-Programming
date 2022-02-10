mp = {}
li = []
for i in range(int(input())):
    f,l, co = map(str, input().split())
    name = f+' '+l
    if co not in li :
        mp[co] = set()
        li.append(co)
    mp[co].add(name)
li.sort()
for co in li:
    print(co, len(mp[co]))
    