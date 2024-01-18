class Solution:
    def maxSumRangeQuery(self, nums: List[int], requests: List[List[int]]) -> int:
        n = len(nums)
        counts = [0] * n
        prefix = [0] * n

        for start, end in requests:
            counts[start] += 1

            if end + 1 < n:
                counts[end + 1] -= 1
        
        prefix[0] = counts[0]
        for i in range(1, n):
            prefix[i] = prefix[i - 1] + counts[i]
        
        prefix.sort()
        nums.sort()

        product = 0
        mod = 10 ** 9 + 7

        for num, count in zip(nums, prefix):
            product += num * count
        
        return product % mod