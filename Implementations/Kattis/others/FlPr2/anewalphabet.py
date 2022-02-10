dic = {'a':'@', 'b':'8', 'c':'(', 'd':'|)', 'e':'3', 'f':'#', 'g':'6', 'h':'[-]', 'i':'|', 'j':'_|', 'k':'|<', 'l':'1', 'm':'[]\/[]',
       'n':'[]\[]', 'o':'0', 'p':'|D', 'q':'(,)', 'r':'|Z', 's':'$', 't':'\'][\'', 'u':'|_|','v':'\/', 'w':'\/\/', 'x':'}{', 'y':'`/', 'z':'2'}

te = list(input())
p = [each_string.lower() for each_string in te]
for i in p:
    if i in dic.keys():
        print(dic[i],end='')
    else:
        print(i,end='')