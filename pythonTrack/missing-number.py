class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        max_ = max(nums)
        nums = set(nums)

        for num in range(max_):
            if num not in nums:
                return num
        
        return  max_ + 1