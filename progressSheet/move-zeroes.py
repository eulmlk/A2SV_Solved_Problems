class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        left, right = 0, 0
        n = len(nums)

        while left < n and right < n:
            while right < n and nums[right] == 0:
                right += 1

            if right < n:
                nums[left], nums[right] = nums[right], nums[left]
            
            left += 1
            right += 1