import sys

a_lst = []
theset=[]
for line in sys.stdin:
    for i in line.split():
        if i.lower() in theset:
            a_lst.append(".")
        else:
            theset.append(i.lower())
            a_lst.append(i)

print(*a_lst,sep=" ")