import re
class Solution:
    def myAtoi(self, str: str) -> int:
        str = str.strip()
        str = re.findall('(^[\+\-0]*\d+)\D*', str)
        try:
            result = int(''.join(str))
            MAX_INT = 2147483647
            return max(-(MAX_INT+1), min(MAX_INT, result))
        except: return 0
