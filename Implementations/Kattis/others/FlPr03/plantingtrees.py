n = int(input())
tree = list(map(int,input().split()))
tree.sort()
tree.reverse()
x = 0
for i in range(2,n+2):
    t = tree[i-2]+i
    if t>x:
        x=t
print(x)
    