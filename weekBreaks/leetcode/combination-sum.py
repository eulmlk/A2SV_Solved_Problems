class Solution:
    def __init__(self):
        sys.setrecursionlimit(2 ** 31 - 1)
    
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        cur = []
        n = len(candidates)

        def comb(i):
            if sum(cur) > target:
                return
            
            if sum(cur) == target:
                result.append(cur.copy())
                return
            
            if i == n:
                return
            
            for j in range(i, n):
                cur.append(candidates[j])
                comb(j)
                cur.pop()
        
        comb(0)
        return result