n,p,m = map(int,input().split())
players = []
for i in range(n): players.append(input())
scores = dict.fromkeys(players,0)
flag = True
for i in range(m):
    name,points = map(str,input().split())
    scores[name]+=int(points)
    if scores[name]==p:
        flag=False
        print(f"{name} wins!")
if flag:
    print("No winner!")
#print(scores)