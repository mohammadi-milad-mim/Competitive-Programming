from itertools import combinations

n,k = map(int, input().split())
know = set(map(int, input().split()))
want = list(map(int, input().split()))
new = []
have = [False]*360

for x in know:
    have[x] = True

cp = know.copy()
for a in cp:
    t = (2*a) % 360
    if not have[t]:
        have[t] = True
        new.append(t)
        know.add(t)
        
for a,b in combinations(know,2):
    t1 = (360+(a-b))%360
    t2 = (360+(b-a))%360
    t3 = (a+b) % 360
    
    if not have[t1]:
        have[t1] = True
        new.append(t1)
        know.add(t1)
        
    if not have[t2]:
        have[t2] = True
        new.append(t2)
        know.add(t2)
        
    if not have[t3]:
        have[t3] = True
        new.append(t3)
        know.add(t3)
        
while new:
    a = new.pop()
    t = (2*a) % 360
    if not have[t]:
        have[t] = True
        new.append(t)
        know.add(t)
        
    cp = know.copy()
    for b in know.copy():
        t1 = (360+(a-b))%360
        t2 = (360+(b-a))%360
        t3 = (a+b) % 360
        if not have[t1]:
            have[t1] = True
            new.append(t1)
            know.add(t1)
           
        if not have[t2]:
            have[t2] = True
            new.append(t2)
            know.add(t2)

        if not have[t3]:
            have[t3] = True
            new.append(t3)
            know.add(t3)
            
for i in want:
    if have[i]:
        print('YES')
    else:
        print('NO')