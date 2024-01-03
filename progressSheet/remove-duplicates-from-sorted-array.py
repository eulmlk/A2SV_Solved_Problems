class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        seek, hold = 1, 0
        n = len(nums)

        while seek < n:
            while seek < n and nums[seek] == nums[hold]:
                seek += 1
            
            if seek < n:
                hold += 1
                nums[hold], nums[seek] = nums[seek], nums[hold]
                seek += 1
        
        return hold + 1