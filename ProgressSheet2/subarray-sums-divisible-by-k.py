class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        prefix = [nums[0] % k]
        n = len(nums)

        for i in range(1, n):
            prefix.append((prefix[-1] + nums[i]) % k)
        
        count = 0
        sums = Counter()

        for curSum in prefix:
            if curSum == 0:
                count += 1
            
            if curSum in sums:
                count += sums[curSum]
            
            sums[curSum] += 1

        return count