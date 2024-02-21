class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:
        n = len(nums)
        total = nums[0]
        curMax = nums[0]

        for i in range(1, n):
            total += nums[i]
            value = (total + i) // (i + 1)
            curMax = max(curMax, value)
        
        return curMax