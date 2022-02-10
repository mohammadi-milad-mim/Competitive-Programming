def inrange(x,y):
    if x>=0 and y>=0 and x<m and y<n:
        return True
    return False

def winner(b,n,m,k):
    for r in range(m):
        for c in range(n):
            side = b[r][c]
            if  side == "o" or side == "x":
                right,down,right_d,right_u = False,False,False,False
                
                for i in range(1,k):
                    if not(inrange(r+i,c)) or b[r+i][c]!=side:
                        break
                else:
                    right=True
                    
                for i in range(1,k):
                    if not(inrange(r,c+i)) or b[r][c+i]!=side:
                        break
                else:
                    down=True
                    
                for i in range(1,k):
                    if not(inrange(r+i,c+i)) or b[r+i][c+i]!=side:
                        break
                else:
                    right_d = True

                for i in range(1,k):
                    if not(inrange(r-i,c+i)) or b[r-i][c+i]!=side:
                        break
                else:
                    right_u = True

                if right or down or right_d or right_u:
                    if side == "o":
                        return 0,1
                    else:
                        return 1,0
    return 0,0

hansel,gretel = 0,0
for tests in range(int(input())):
    board = []
    n,m,k = map(int,input().split())
    for i in range(m):
        board.append(list(input()))
    h,g = winner(board,n,m,k)
    hansel += h
    gretel += g
print(hansel,':',gretel,sep="")