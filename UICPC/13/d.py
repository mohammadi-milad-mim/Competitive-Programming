import math
n = int(input())
li = [[0,0,0,0,0]*n]
maxdays = 0
for i in range(n):
    y,i,s,b = map(int,input().split())
    plantedend=math.ceil(s/i)
    cDays = s+(2*y)+plantedend
    li[i]=[y,i,s,b,cDays]
    if cDays >=maxdays: maxdays = cDays