class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        n = len(nums)
        index = 0

        for i, num in enumerate(nums):
            if num != val:
                nums[i], nums[index] = nums[index], nums[i]
                index += 1
        
        return index