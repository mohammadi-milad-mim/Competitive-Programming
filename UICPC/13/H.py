def BSI(arr, x,num):
    low = 0
    high = len(arr)-1
    while low <= high:
        mid = low + (high - low) // 2
        if arr[mid][0] == x:
            arr[mid][1]+=num
            return arr
        elif arr[mid][0] < x:
            high = mid - 1
        else:
            low = mid + 1
    arr = arr[:high+1] + [[x,num]] + arr[high+1:]
    return arr

for i in range(int(input())):
    buys = []
    sells = []
    stockP, ask, bid = -1,-1,-1
    for j in range(int(input())):
        li = list(input().split())
        num = int(li[1])
        price = int(li[4])
        if li[0]=='buy':
            if len(buys):
                buys = BSI(buys,price,num)
            else:
                buys.append([price,num])
            
            flag=True
            while (len(sells) and len(buys) and flag):
                while (buys[0][0]>=sells[-1][0]):
                    if buys[0][1]==sells[-1][1]:
                        stockP=sells[-1][0]
                        del buys[0]
                        del sells[-1]
                    elif buys[0][1]>sells[-1][1]:
                        buys[0][1]-=sells[-1][1]
                        stockP=sells[-1][0]
                        del sells[-1]
                    else:
                        sells[-1][1]-=buys[0][1]
                        stockP=sells[-1][0]
                        del buys[0]
                    if (len(sells) and len(buys)): continue
                    else: break
                flag=False
            
            if (len(sells)): ask = sells[-1][0]
            else: ask = -1
            if (len(buys)): bid=buys[0][0]
            else: bid = -1
            print((ask if ask!=-1 else '-'),(bid if bid!=-1 else '-'),(stockP if stockP!=-1 else '-'))
        
        else:
            if len(sells):
                sells = BSI(sells,price,num)
            else:
                sells.append([price,num])
            #print(buys)
            #print(sells)
            flag = True
            while (len(sells) and len(buys) and flag):
                while (buys[0][0]>=sells[-1][0]):
                    if buys[0][1]==sells[-1][1]:
                        stockP=sells[-1][0]
                        del buys[0]
                        del sells[-1]
                    elif buys[0][1]>sells[-1][1]:
                        buys[0][1]-=sells[-1][1]
                        stockP=sells[-1][0]
                        del sells[-1]
                    else:
                        sells[-1][1]-=buys[0][1]
                        stockP=sells[-1][0]
                        del buys[0]
                    if (len(sells) and len(buys)): continue
                    else: break
                flag=False
            if (len(sells)): ask = sells[-1][0]
            else: ask = -1
            if (len(buys)): bid=buys[0][0]
            else: bid = -1
            print((ask if ask!=-1 else '-'),(bid if bid!=-1 else '-'),(stockP if stockP!=-1 else '-'))

    #print(buys)
    #print(sells)