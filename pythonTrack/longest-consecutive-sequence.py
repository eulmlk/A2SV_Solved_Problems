class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numSet = set(nums)
        longest = 0

        for num in nums:
            if num - 1 in numSet:
                continue
            
            length = 1
            cur = num
            while cur + 1 in numSet:
                length += 1
                cur += 1
            
            longest = max(longest, length)
        
        return longest