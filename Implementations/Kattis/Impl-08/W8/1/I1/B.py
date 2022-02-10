a,b = map(int,input().split())
res = (a-((2**(b+1))-1))
if res<=0: print('yes')
else: print('no')