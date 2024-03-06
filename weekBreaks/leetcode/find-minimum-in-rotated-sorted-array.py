class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        left, right = 0, n - 1

        while nums[right] < nums[left]:
            mid = (left + right) // 2

            if nums[right] > nums[mid]:
                right = mid
            else:
                left = mid + 1
        
        return nums[left]