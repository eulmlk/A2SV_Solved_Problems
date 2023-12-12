class Solution:
    def isHappy(self, n: int) -> bool:
        while True:
            num = str(n)
            if len(num) == 1:
                return num[0] in "17"
            
            result = 0
            for digit in num:
                digit = int(digit)
                result += digit * digit
            
            n = result
        
