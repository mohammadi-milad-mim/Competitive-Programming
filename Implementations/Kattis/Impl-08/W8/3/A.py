def inrnage(x,y):
    if (x<7 and y<7 and x>=0 and y>=0 and mp[x]!=' ' and mp[y]!=' '):
        return True
    else:
        return False

def right(x,y):
    if inrnage(x,y+2) and mp[x][y+2]=='.' and mp[x][y+1]=='o':
        return 1
    else:
        return 0
def left(x,y):
    if inrnage(x,y-2) and mp[x][y-2]=='.' and mp[x][y-1]=='o':
        return 1
    else:
        return 0
def up(x,y):
    if inrnage(x-2,y) and mp[x-2][y]=='.' and mp[x-1][y]=='o':
        return 1
    else:
        return 0
def down(x,y):
    if inrnage(x+2,y) and mp[x+2][y]=='.' and mp[x+1][y]=='o':
        return 1
    else:
        return 0
#mp = [[-1,-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1,-1]]
mp=[]
for i in range(7):
    mp.append(list(input()))
count=0
for i in range(7):
    for j in range(7):
        if (mp[i][j]=='o'):
            count+=right(i,j)+left(i,j)+down(i,j)+up(i,j)
print(count)