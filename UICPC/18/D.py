import math 
def me(s,e,n):
    li = list(range(s, e+1))
    return sum(li)/n

n , k = map(int, input().split())
start = 1
end = n
exp = me(start,end,n)
for i in range(1,k):
    fl = math.floor(exp)
    start = fl+1
    exp = me(start,end,n) + (fl*exp/n)
print(exp)