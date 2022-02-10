a,b = map(int,input().split())
dif = b-a
if dif<0:
    print("Dr. Chaz needs {} more piece{} of chicken!".format(abs(dif), 's' if abs(dif)>1 else ''))
else:
    print("Dr. Chaz will have {} piece{} of chicken left over!".format(dif, 's' if dif>1 else ''))