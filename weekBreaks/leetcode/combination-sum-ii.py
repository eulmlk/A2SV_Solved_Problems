class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        cur = []

        candidates = Counter(candidates)
        candidates = [(num, count) for num, count in candidates.items()]
        n = len(candidates)

        def comb(ind):
            if sum(cur) == target:
                result.append(cur.copy())
                return

            if sum(cur) > target or ind >= n:
                return
            
            for _ in range(candidates[ind][1]):
                cur.append(candidates[ind][0])
                comb(ind + 1)
            
            for _ in range(candidates[ind][1]):
                cur.pop()
            
            comb(ind + 1)

        comb(0)
        return result
