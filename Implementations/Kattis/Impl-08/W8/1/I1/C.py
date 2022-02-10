for T in range(int(input())):
    i,n = map(str,input().split())
    
    try:
        num16 = int(('0x'+n), 16)
    except:
        num16 = 0
    try:
        num8 = int(('0'+n), 8)
    except:
        num8 = 0
    try:
         num10 = int(n)
    except:
        num10 = 0
        
    print(i,num8,num10,num16,sep=' ')