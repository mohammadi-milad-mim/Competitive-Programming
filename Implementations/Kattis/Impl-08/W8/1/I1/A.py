import math
for T in range(int(input())):
    a,b = map(int,input().split())
    if b > a: a,b = b,a
    bb = -(4*(a+b))
    aa = 12
    cc = (a * b)
    h1 = (-bb+(math.sqrt((bb**2)-(4*aa*cc))))/(2*aa)
    h2 =  (-bb-(math.sqrt((bb**2)-(4*aa*cc))))/(2*aa)
    if (b-2*h1)<=0: h = h2
    else: h = h1
    aaa = a - 2 * h
    bbb = b - 2 * h
    print('{0:.7f}'.format(aaa*bbb*h))