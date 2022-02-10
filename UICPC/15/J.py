li = list(map(int,input().split()))
ctime=0
cmachine = 0
jim = [0,0,0,0,0,0,0]
oth = [0,0,0,0,0,0,0]
for i in range(10):
    uj, rj, tj = li[2*i], li[2*i+1],ctime
    jim[0]=tj
    jim[1]=jim[0]+uj
    jim[2]=jim[1]+rj
    jim[3]=jim[2]+uj
    jim[4]=jim[3]+rj
    jim[5]=jim[4]+uj
    jim[6]=jim[5]+rj

    uo, ro, to = map(int,input().split())
    oth[0]=to
    oth[1]=oth[0]+uo
    oth[2]=oth[1]+ro
    oth[3]=oth[2]+uo
    oth[4]=oth[3]+ro
    oth[5]=oth[4]+uo
    oth[6]=oth[5]+ro
    
    
    if jim[-2] < oth[0]:
        ctime = jim[-1]
        continue
    elif oth[-2] < jim[0]:
        ctime = jim[-1]
        continue
    else:
        jrep=0
        orep =0
        while (jrep<3 and orep<3):
            #print(jim)
            #print(oth)
            sj = jim[jrep*2]
            ej = jim[jrep*2+1]
            so = oth[orep*2]
            eo = oth[orep*2+1]
            if so<=sj:
                orep+=1
                if sj < eo:
                    wait = eo - sj
                    new_list = [x+wait for x in jim]
                    jim = new_list
            else:
                jrep+=1
                if so < ej:
                    wait = ej-so
                    new_list = [x+wait for x in oth]
                    oth = new_list
            
        ctime = jim[-1]
    print(ctime)
print(ctime)