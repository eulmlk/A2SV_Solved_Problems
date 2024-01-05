class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        n = len(nums)
        sum_ = sum(nums[:k - 1])
        maxAvg = float('-inf')

        for i in range(n - k + 1):
            sum_ += nums[i + k - 1]
            maxAvg = max(sum_ / k, maxAvg)
            sum_ -= nums[i]
        
        return maxAvg