class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        n = len(nums)
        stack = []
        curMin = float('inf')

        for num in nums:
            while stack and num >= stack[-1][0]:
                val, minVal = stack.pop()
            
            if stack and num > stack[-1][1]:
                return True
                
            curMin = min(curMin, num)
            stack.append((num, curMin))
        
        return False