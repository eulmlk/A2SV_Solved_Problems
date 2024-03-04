class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        result = []
        cur = []
        nums.sort()
        n = len(nums)

        def subs(i):
            if i == n:
                result.append(cur.copy())
                return
            
            cur.append(nums[i])
            subs(i + 1)
            cur.pop()

            while i < n - 1 and nums[i] == nums[i + 1]:
                i += 1
            
            subs(i + 1)
        
        subs(0)
        return result