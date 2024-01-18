class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        n = len(nums)
        prefix = [0] * n

        prefix[0] = nums[0]
        for i in range(1, n):
            prefix[i] = prefix[i - 1] + nums[i]

        sums = Counter()
        count = 0
        for curSum in prefix:
            if curSum == goal:
                count += 1
            
            if curSum - goal in sums:
                count += sums[curSum - goal]
            
            sums[curSum] += 1
        
        return count