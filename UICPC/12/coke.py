for i in range(int(input())):
    n,c1,c5,c10 = map(int, input().split())
    val = n*8
    now = 0
    if c10 >= n:
        print(n)
        continue
    if c10 > 0:
        now+=c10
        val -= (now*8)
        c1+=(2*c10)
        n-=now
    if (c5//2) >= n:
        cc5 = c5//2
        dif = cc5 - n
        now+=(dif*2)
        print(now)
        continue
    else:
        while(n>0):
            if c1<3 and c5>2:
                c5-=2
                c1+=2
                now+=2
                n-=1
            elif c1>3 and c5>1:
                c5-=1
                c1-=3
                now+=4
                n-=1
            elif c1>3 and c5<1:
                x = n*8
                now+=x
                n-=n
        print(now)
        continue
    