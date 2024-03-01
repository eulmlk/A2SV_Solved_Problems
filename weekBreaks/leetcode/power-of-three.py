class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        def isPower(num):
            if num == 1:
                return True
            
            if num < 1:
                return False
            
            return isPower(num / 3)
        
        return isPower(n)