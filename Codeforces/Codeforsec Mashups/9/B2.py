first = list(input())
sec = list(input())
te = first + sec
te.sort()
third = list(input())
third.sort()
if te==third:
    print("YES")
else:
    print("NO")
    
    
s,i=sorted,input;print('YNEOS'[s(i()+i())!=s(i())::2])

