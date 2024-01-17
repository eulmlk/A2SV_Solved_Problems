class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefix = [nums[0]]
        n = len(nums)

        for i in range(1, n):
            prefix.append(prefix[-1] + nums[i])
        
        count = 0
        sums = Counter()

        for curSum in prefix:
            if curSum == k:
                count += 1
            
            if curSum - k in sums:
                count += sums[curSum - k]
            
            sums[curSum] += 1

        return count