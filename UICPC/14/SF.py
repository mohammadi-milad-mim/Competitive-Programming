from itertools import combinations as C

def find_all_possible(known):
    possible = [False]*360
    for x in known:
        possible[x] = True

    stack = []
    cp = known.copy()
    for a in cp:
        t = (2*a) % 360
        if not possible[t]:
            stack.append(t)
            known.add(t)
            possible[t] = True
    
    for a1,a2 in C(known,2):
        t1 = (360+a1-a2)%360
        t2 = (360+a2-a1)%360
        t3 = (a1+a2) % 360
        if not possible[t1]:
            stack.append(t1)
            known.add(t1)
            possible[t1] = True
        if not possible[t2]:
            stack.append(t2)
            known.add(t2)
            possible[t2] = True
        if not possible[t3]:
            stack.append(t3)
            known.add(t3)
            possible[t3] = True
    
    while stack:
        a1 = stack.pop()
        t = (2*a1) % 360
        if not possible[t]:
            stack.append(t)
            known.add(t)
            possible[t] = True
        
        cp = known.copy()
        for a2 in known.copy():
            t1 = (360+a1-a2)%360
            t2 = (360+a2-a1)%360
            t3 = (a1+a2) % 360
            if not possible[t1]:
                stack.append(t1)
                known.add(t1)
                possible[t1] = True
            if not possible[t2]:
                stack.append(t2)
                known.add(t2)
                possible[t2] = True
            if not possible[t3]:
                stack.append(t3)
                known.add(t3)
                possible[t3] = True
    
    return possible


def main():
    input()#DUMP
    possible = find_all_possible(set(map(int,input().split())))
    for x in map(int,input().split()):
        print('YES' if possible[x] else 'NO')

if __name__ == "__main__":
    main()