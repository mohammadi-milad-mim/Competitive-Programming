while(True):
    s0,s1, r0,r1 = map(int,input().split())
    if not(s0):
        exit() 
    S0,S1=min(s0,s1),max(s0,s1)
    R0,R1=min(r0,r1),max(r0,r1)
    if S0+S1==3 and R0+R1==3:
        print("Tie.")
    elif S0+S1==3:
        print("Player 1 wins.")
    elif R0+R1==3:
        print("Player 2 wins.")
    elif S0==S1 and R0==R1:
        if S0>R0:
            print("Player 1 wins.")
        elif R0>S0:
            print("Player 2 wins.")
        else:
            print("Tie.")
    elif S0==S1:
        print("Player 1 wins.")
    elif R0==R1:
        print("Player 2 wins.")
    elif S1>R1:
        print("Player 1 wins.")
    elif S1<R1:
        print("Player 2 wins.")
    elif S1==R1:
        if S0>R0:
            print("Player 1 wins.")
        elif S0<R0:
            print("Player 2 wins.")
        else:
            print("Tie.")