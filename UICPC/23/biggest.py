import math

def conv(d, m, s):
    dd = d + float(m)/60 + float(s)/3600
    return dd%360

for i in range(int(input())):
    r,n,d,m,s = map(int,input().split())
    circle = math.pi * r * r
    deg = conv(d,m,s)
    N = 360/deg
    Ni = math.floor(N)
    if Ni > n:
        total_deg = n*deg
        remain_deg = 360 - total_deg
        if remain_deg > deg:
            res = circle * (remain_deg/360)
        else:
            res = circle * (deg/360)
    else:
        if (N==Ni):
            res = circle * (deg/360)
        else:
            res1 = circle * (deg/360)
            res2 = circle * (1- ((deg/360)*n))
            if res1>res2:
                res = res1
            else:
                res = res2
    print("{:.6f}".format(res))