class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        maxOnes = -inf
        curOnes = 0

        for num in nums:
            if num == 0:
                maxOnes = max(curOnes, maxOnes)
                curOnes = 0
            else:
                curOnes += 1
        
        maxOnes = max(curOnes, maxOnes)
        
        return maxOnes