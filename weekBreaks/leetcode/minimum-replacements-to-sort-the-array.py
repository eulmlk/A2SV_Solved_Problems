class Solution:
    def minimumReplacement(self, nums: List[int]) -> int:
        n = len(nums)
        last = nums[-1]
        steps = 0

        for i in range(n - 2, -1, -1):
            if nums[i] <= last:
                last = nums[i]
                continue
            
            splits = (nums[i] + last - 1) // last
            last = nums[i] // splits
            steps += splits - 1
            
        return steps
