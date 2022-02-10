for i in range(int(input())):
    m,q = map(int,input().split())
    stac = [i+1 for i in range(m)]
    print(stac)
    quer = list(map(int,input().split()))
    for i in quer:
        indx = stac.pop()