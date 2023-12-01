class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        nums = [1] * 17

        for i in range(1, 17):
            nums[i] = nums[i - 1] * 3
        
        for i in range(16, -1, -1):
            if n == nums[i]:
                return True
            
            if n > nums[i]:
                n -= nums[i]
        
        return n == 0