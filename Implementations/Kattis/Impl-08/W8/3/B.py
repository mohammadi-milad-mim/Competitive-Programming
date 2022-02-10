x1,y1 = map(int, input().split())
x2,y2 = map(int, input().split())
dis = abs(x1-x2)+abs(y1-y2)
gas = int(input())
res = gas - dis
if res<0:
    print('N')
elif res%2==0:
    print('Y')
else:
    print('N')
    