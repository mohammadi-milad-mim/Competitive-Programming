from typing import Counter


def inrange(x , y):
    if x<0 or y < 0 or x>=8 or y>=8:
        return False
    else:
        return True

mp = []
for i in range(8):
    mp.append(list(input()))
ins = list(input())
dirs = [[0,1],[1,0],[0,-1],[-1,0]]
di = 0
x = 7
y = 0
mp[x][y]='.'
for i in ins:
    #print(i)
    mvx = dirs[di][0]
    mvy = dirs[di][1]
    if i == 'F':
        if (inrange(x+mvx,y+mvy)):
            x+=mvx
            y+=mvy
            if (mp[x][y]=='C' or mp[x][y]=='I'):
                print('Bug!')
                exit()
            elif (mp[x][y]=='D'):
                continue
        else:
            print('Bug!')
            exit()
    elif i == 'R':
        di = (di+1)%4
    elif i == 'L':
        di = (di-1)%4
    elif i == 'X':
        if di==0:
            yy=y+1
            #for yy in range(y+1,7):
            if (mp[x][yy]=='I') and (inrange(x,yy)):
                mp[x][yy]='.'
            else:
                print('Bug!')
                exit()
        elif di == 1:
            xx=x+1
            #for xx in range(x+1,7):
            if (mp[xx][y]=='I')  and (inrange(xx,y)):
                mp[xx][y]='.'
            else:
                print('Bug!')
                exit()
        elif di == 2:
            yy=y-1
            #for yy in range(y-1,0,-1):
            if (mp[x][yy]=='I')  and (inrange(x,yy)):
                mp[x][yy]='.'
            else:
                print('Bug!')
                exit()
        elif di==3:
            xx=x-1
            #for xx in range(x-1,0,-1):
            if (mp[xx][y]=='I')  and (inrange(xx,y)):
                mp[xx][y]='.'
            else:
                print('Bug!')
                exit()
if (mp[x][y]=='D'):
    print("Diamond!")
else:
    print("Bug!")