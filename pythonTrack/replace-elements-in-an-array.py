class Solution:
    def arrayChange(self, nums: List[int], operations: List[List[int]]) -> List[int]:
        n = len(nums)
        nums = {num: ind for ind, num in enumerate(nums)}

        for old, new in operations:
            ind = nums.pop(old)
            nums[new] = ind
        
        result = [0] * n
        for num, ind in nums.items():
            result[ind] = num

        return result