class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        mod = 10 ** 9 + 7
        nums.sort()
        n = len(nums)
        total = 0

        for left in range(n):
            value = target - nums[left]
            right = bisect_right(nums, value)
            
            curLen = right - left
            if curLen > 0:
                total += pow(2, curLen - 1, mod)
        
        return total % mod
