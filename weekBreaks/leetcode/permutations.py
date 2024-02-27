class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []
        cur = []
        n = len(nums)

        def permut(i):
            if i == n:
                result.append(cur.copy())
                return
            
            for j in range(n):
                if nums[j] in cur:
                    continue
                
                cur.append(nums[j])
                permut(i + 1)
                cur.pop()
        
        permut(0)
        return result