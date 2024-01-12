class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        left = 0
        curSum = 0
        maxSum = -1
        counts = Counter()

        for right in range(n):
            curSum += nums[right]
            counts[nums[right]] += 1

            while left < n and counts[nums[right]] > 1:
                curSum -= nums[left]
                counts[nums[left]] -= 1
                left += 1

            maxSum = max(maxSum, curSum)
        
        return maxSum