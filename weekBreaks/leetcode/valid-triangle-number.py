class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        count = 0

        for i in range(n):
            for j in range(i + 1, n):
                sides = nums[i] + nums[j]
                
                left, right = j + 1, n - 1
                while left <= right:
                    mid = (left + right) // 2

                    if nums[mid] < sides:
                        left = mid + 1
                    else:
                        right = mid - 1
                
                count += left - j - 1
        
        return count
