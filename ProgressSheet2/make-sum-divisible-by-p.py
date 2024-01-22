class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        n = len(nums)
        prefix = [0] * n

        prefix[0] = nums[0]
        for i in range(1, n):
            prefix[i] = prefix[i - 1] + nums[i]

        total = prefix[-1]
        if total < p:
            return -1
        
        if total % p == 0:
            return 0
        
        prefix = [value % p for value in prefix]

        required = prefix[-1]
        indices = {}
        minLen = n

        for index, curSum in enumerate(prefix):
            if curSum == required:
                minLen = min(minLen, index + 1)

            prevSum = (curSum - required) % p
            if prevSum in indices:
                left = indices[prevSum]
                minLen = min(minLen, index - left)
            
            indices[curSum] = index

        return -1 if minLen == n else minLen