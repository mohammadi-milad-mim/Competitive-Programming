for i in range(int(input())):
    tem = list(input().split())
    if tem[0]=="Simon" and tem[1]=="says":
        print(*tem[2:],sep=' ')