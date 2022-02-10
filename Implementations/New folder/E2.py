command = input()
command = command.strip()
tokens = []
numbers = ['0','1','2','3','4','5','6','7','9']
if (command[:4]=="cout" and command[-1]==';'):
    index = 4
    while(True):
        if(command[index]=='<' and command[index+1]=='<'):
            index+=2
            s=""
            while(command[index]!='<' and command[index]!=';'):
                s+=command[index]
                index+=1
            tokens.append(s)
            if (command[index]==';'):
                break
            elif (command[index]=='<'):
                continue
            else:
                print("ERROR!")
                exit()
        else:
            print("ERROR")
            exit()
else:
    print("ERROR")
    exit()

print(tokens)
cout = []
for t in tokens:
    to = t.strip()
    num=""
    i=0
    if (to[0]=='\"' and to[-1]=='\"'):
        cout.append(to[1:len(to)-1])
    elif (to[i] in numbers):
        while(i!= len(to) and to[i] in numbers):
            num+=to[i]
            i+=1
        if (i!=len(to)):
            print("ERROR")
            exit()
        else:
            cout.append(num)
    elif (to=="endl"):
        cout.append(-1)
    else:
        print("ERROR!!")
        exit()
for p in cout:
    if p==-1:
        print('\n',end='')
    else:
        print(p,end=' ')