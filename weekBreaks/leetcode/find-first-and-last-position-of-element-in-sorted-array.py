class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        first, last = -1, -1

        left, right = 0, n - 1
        while left <= right:
            mid = (left + right) // 2

            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        
        if left < n and nums[left] == target:
            first = left

        left, right = 0, n - 1
        while left <= right:
            mid = (left + right) // 2

            if nums[mid] > target:
                right = mid - 1
            else:
                left = mid + 1
        
        if right >= 0 and nums[right] == target:
            last = right
        
        return [first, last]