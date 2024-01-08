class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        #             v
        # 2 3 1 2 4 3
        #           ^

        # 3
        left, right = 0, 0
        sum_, n = 0, len(nums)
        minLen = float('inf')

        while left < n and right <= n:
            while right < n and sum_ < target:
                sum_ += nums[right]
                right += 1

            if sum_ >= target:            
                minLen = min(minLen, right - left)

            sum_ -= nums[left]
            left += 1
        
        return 0 if minLen == float('inf') else minLen