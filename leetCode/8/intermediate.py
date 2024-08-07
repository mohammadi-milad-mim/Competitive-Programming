class Solution:
  def myAtoi(self, s: str) -> int:
    int_max = 2**31 - 1
    int_min = (int_max+1)*-1
    
    trimmedStr = s.strip()
    
    numericStr = ''
    
    if trimmedStr and (trimmedStr[0].isdigit()) or (len(trimmedStr) > 1 and trimmedStr[0] in ['+', '-'] and trimmedStr[1].isdigit()):
      numericStr = trimmedStr[0]
      for char in trimmedStr[1:]:
        if char.isdigit():
          numericStr += char
        else:
          break

      result = int(numericStr)
    else:
      return 0
    
    return max(int_min, min(int_max, result))
