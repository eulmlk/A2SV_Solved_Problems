class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        result = []
        cur = []
        n = len(nums)

        def subs(i):
            if i == n:
                result.append(cur.copy())
                return
            
            cur.append(nums[i])
            subs(i + 1)
            cur.pop()
            subs(i + 1)
        
        subs(0)
        result = set(map(lambda x: tuple(sorted(x)), result))
        result = list(map(lambda x: list(x), result))
        return result