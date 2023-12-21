class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        size = len(nums)
        
        left = float('inf')
        mid = float('inf')

        for num in nums:
            if num > mid:
                return True
            
            if num > left and num < mid:
                mid = num
            elif num < left:
                left = num

        return False