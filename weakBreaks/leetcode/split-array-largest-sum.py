class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:
        n = len(nums)

        def check(target):
            splits = 1
            maxSum = 0
            curSum = 0

            for num in nums:
                if curSum + num > target:
                    maxSum = max(curSum, maxSum)
                    curSum = num
                    splits += 1
                else:
                    curSum += num

            maxSum = max(curSum, maxSum)
            return splits <= k

        left, right = max(nums), sum(nums)

        while left <= right:
            mid = (left + right) // 2

            if check(mid):
                right = mid - 1
            else:
                left = mid + 1
        
        return left