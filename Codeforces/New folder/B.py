for i in range(int(input())):
    n = int(input())
    nums = list(map(int,input().split()))
    if (n==1):
        if (nums[0]):
            tall=2
        else:
            tall=1
        print(tall)
    else:
        if (nums[0]):
            c=1
            tall=2
        else:
            c=0
            tall=1
        for i in range(1,n):
            if (nums[i] and c==1):
                tall+=5
            elif (nums[i] and c==0):
                tall+=1
                c=1
            elif (nums[i]==0 and c==1):
                c=0
                continue
            else:
                tall=-1
                break
        print(tall)