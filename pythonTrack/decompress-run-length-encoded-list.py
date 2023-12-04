class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        final = []
        i = 0
        n = len(nums)

        while i < n:
            final += [nums[i + 1]] * nums[i]
            i += 2
        
        return final