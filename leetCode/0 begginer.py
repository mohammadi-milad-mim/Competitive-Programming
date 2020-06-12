class Solution:
    def myAtoi(self, str: str) -> int:
        sign=''
        str2=''
          
        for i in str:
            if i.isdigit():
                str2+=i
            else:
                if len(str2)!= 0:
                    break
                elif (i == '+' or i =='-') and sign=='':
                    sign+=i
                elif i == ' ':
                    if sign=='':
                        continue
                    else:
                        return(0)
                else:
                    return(0)
     
        if not(len(str2)):
            return(0)
        
        str2=sign+str2
        ourNum=int(str2)
                
        intMax=(2**31) - 1
        intMin = -1 * (2**31)

        if ourNum > intMax:
            ourNum = intMax
        if ourNum < intMin:
            ourNum = intMin
        return(ourNum)
    
print(Solution.myAtoi("",input()))