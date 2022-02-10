for i in range(int(input())):
    s = list(input())
    t = list(input())
    s.sort()
    if not(t[0]=='a' and t[1]=='b' and t[2]=='c'):
        print(*s, sep='')
    else:
        res = ""
        maxi = -1
        c1=0
        c2=0
        c3=0
        for i in range(len(s)):
            if s[i]==t[0]:
                res+=s[i]
                if i> maxi: maxi = i
                c1+=1
        for i in range(len(s)):
            if s[i]==t[2]:
                res+=s[i]
                if i> maxi: maxi = i
                c2+=1
        for i in range(len(s)):
            if s[i]==t[1]:
                res+=s[i]
                if i> maxi: maxi = i
                c3+=1
        if (c1==0 or c2==0 or c3==0):
            print(*s, sep='')
        else:
            for i in range(maxi+1,len(s)):
                res+=s[i]
            print(*res,sep='')