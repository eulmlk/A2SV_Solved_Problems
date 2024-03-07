class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        nums.sort()

        def check(div):
            curSum = 0
            for num in nums:
                curSum +=  (num + div - 1) // div
            
            return curSum <= threshold
        
        left, right = 1, nums[-1]

        while left <= right:
            mid = (left + right) // 2

            if check(mid):
                right = mid - 1
            else:
                left = mid + 1
        
        return left

