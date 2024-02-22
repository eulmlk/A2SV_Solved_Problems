class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        stack = []
        result = [-1] * n

        for i in range(2 * n):
            i %= n

            while stack and nums[i] > nums[stack[-1]]:
                ind = stack.pop()
                result[ind] = nums[i]
            
            stack.append(i)
        
        return result