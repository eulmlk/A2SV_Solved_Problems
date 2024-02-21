class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        cur = -1

        for i in range(n - 1):
            cur = max(nums[i], cur)

            if cur == 0:
                return False
            
            cur -= 1
        
        return True
        