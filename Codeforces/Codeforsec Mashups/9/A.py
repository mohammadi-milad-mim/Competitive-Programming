num = int(input())

b100 = num//100
num-= b100*100
b20 = num//20
num-= b20*20
b10= num//10
num-= b10*10
b5= num//5
num-= b5*5
print(b100+b20+b10+b5+num)

