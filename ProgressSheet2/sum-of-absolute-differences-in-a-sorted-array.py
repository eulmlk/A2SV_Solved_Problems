class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        n = len(nums)
        prefixLeft, prefixRight = [0] * n, [0] * n

        for i in range(1, n):
            prefixLeft[i] = prefixLeft[i - 1] + nums[i - 1]
        
        for i in range(n - 2, -1, -1):
            prefixRight[i] = prefixRight[i + 1] + nums[i + 1]
        
        result = [0] * n
        for i in range(n):
            result[i] += i * nums[i] - prefixLeft[i]
            result[i] += prefixRight[i] - (n - i - 1) * nums[i]

        return result