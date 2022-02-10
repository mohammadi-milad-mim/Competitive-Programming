command = input()
command = command.strip()
tokens = []
numbers = [0,1,2,3,4,5,6,7,9]
if (command[:4]=="cout" and command[-1]==';'):
    index = 4
    while(command[index]=='<' and command[index+1]=='<'):
        index+=2
        if (command[index]=='\"'):
            s=""
            index+=1
            while(command[index]!='\"'):
                s+=command[index]
                index+=1
            index+=1
            while (command[index]==' '):
                index+=1
            if (command[index]=='<'):
                continue
            elif (command[index]==';'):
                break
            else:
                print("ERROR")
                exit()
        elif (command[index] in numbers):
            num = ""
            num+=command[index]
            index+=1
            while(command[index] in numbers):
                num+=command[index]
                index+=1
    else:
        print("ERROR")
        exit()
else:
    print("ERROR")