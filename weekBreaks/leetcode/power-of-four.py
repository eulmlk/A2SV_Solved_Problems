class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        def isPower(num):
            if num == 1:
                return True
            
            if num < 1:
                return False
            
            return isPower(num / 4)
        
        return isPower(n)