inp = list(input())
pas = ""
curs = 0
for i in inp:
    if i=='R':
        curs+=1
    elif i=='L':
        curs-=1
    elif i=='B':
        pas = pas[:curs-1]+pas[curs:]
        curs-=1
    else:
        if curs == 0:
            pas= i + pas
            curs+=1
        elif curs == len(pas):
            pas = pas + i
            curs+=1
        else:
            pas = pas[:curs]+i+pas[curs:]
print(pas)