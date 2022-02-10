import sys

for line in sys.stdin:
    te = list(line.split())
    if len(te)==1:
        n = int(te[0])
        ii = n
        #ds = []
        stac = []
        que = []
        pque=[]
        stf = True
        quf = True
        pquf = True
    else:
        ii-=1
        c,x = int(te[0]), int(te[1])
        if c==1:
            #ds.append(x)
            stac.append(x)
            que.append(x)
            pque.append(x)
        if c==2:
            
            if len(stac):
                if x!=stac[-1]: stf=False
                elif x==stac[-1] and stf: del stac[-1]
            else: stf = False
            
            if len(que):
                if x!=que[0]: quf=False
                elif x==que[0] and quf: del que[0]
            else: quf=False
            
            if len(pque):
                ma = max(pque)
                if x!=ma: pquf=False
                elif  x==ma and pquf: pque.remove(x)
            else: pquf=False
            
            
        if ii==0 :
            if (stf and quf) or (stf and pquf) or (pquf and quf):
                print("not sure")
            elif stf:
                print("stack")
            elif quf:
                print("queue")
            elif pquf:
                print("priority queue")
            else:
                print("impossible")
                