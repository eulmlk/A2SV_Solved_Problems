class Solution:
    def findMiddleIndex(self, nums: List[int]) -> int:
        prefix = [0, nums[0]]
        n = len(nums)

        for i in range(1, n):
            prefix.append(prefix[-1] + nums[i])
        
        for i in range(n):
            left = prefix[i]
            right = prefix[-1] - prefix[i + 1]
            
            if left == right:
                return i
            
        return -1