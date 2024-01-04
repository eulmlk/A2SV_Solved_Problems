class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()

        closest = -1
        minDiff = inf

        for i in range(len(nums) - 2):
            if i and nums[i] == nums[i - 1]:
                continue
            
            left = i + 1
            right = len(nums) - 1

            while left < right:
                curSum = nums[i] + nums[left] + nums[right]
                diff = abs(curSum - target)
                if diff < minDiff:
                    minDiff = diff
                    closest = curSum
                
                if curSum < target:
                    left += 1
                else:
                    right -= 1
    
        return closest