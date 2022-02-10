M,N = map(int,input().split())

def preProcess(mat, aux):
     
    for i in range(0, N, 1):
        aux[0][i] = mat[0][i]
 
    for i in range(1, M, 1):
        for j in range(0, N, 1):
            aux[i][j] = mat[i][j] + aux[i - 1][j]
 
    for i in range(0, M, 1):
        for j in range(1, N, 1):
            aux[i][j] += aux[i][j - 1]
 
def sumQuery(aux, tli, tlj, rbi, rbj):
    res = aux[rbi][rbj]
    if (tli > 0):
        res = res - aux[tli - 1][rbj]
 
    if (tlj > 0):
        res = res - aux[rbi][tlj - 1]
        
    if (tli > 0 and tlj > 0):
        res = res + aux[tli - 1][tlj - 1]
 
    return res

mat = []
for i in range(M):
    temp = list(map(int,input().split()))
    mat.append(temp)

aux = [[0 for i in range(N)] for j in range(M)]
preProcess(mat, aux)

T = int(input())

for i in range(T):
    tli,rbi,tlj,rbj =map(int,input().split())
    print(sumQuery(aux, tli, tlj, rbi, rbj))

