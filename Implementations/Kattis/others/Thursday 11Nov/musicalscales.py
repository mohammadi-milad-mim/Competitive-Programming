notes = ['A' , 'A#', 'B', 'C', "C#", "D", "D#", "E", "F", "F#", "G", "G#"]
majors=[]
squence = [2,4,5,7,9,11,12]
n = len(notes)
for i in range(n):
    li = [notes[i]]
    for j in squence:
        li.append(notes[(i+j)%n])
    majors.append(li)
#print(majors)
num = int(input())
ipu = list(input().split())
ipu = set(ipu)
ipu.discard(' ')
sn = len(ipu)
#print(ipu)
ff=True
for maj in majors:
    c=0
    for no in ipu:
        if no in maj:
            c+=1
    #print(sn,c)
    if c==sn:
        ff=False
        print(maj[0],end=" ")
if ff:
    print("none")
