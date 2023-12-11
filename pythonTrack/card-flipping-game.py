class Solution:
    def flipgame(self, fronts: List[int], backs: List[int]) -> int:
        n = len(fronts)
        canFlips = set(fronts)
        frontSet = set(fronts)

        for i in range(n):
            if fronts[i] == backs[i]:
                canFlips.discard(fronts[i])

        for i in range(n):
            if (fronts[i] < backs[i] or backs[i] in frontSet) and fronts[i] in canFlips:
                frontSet.discard(fronts[i])
                frontSet.add(backs[i])
                fronts[i], backs[i] = backs[i], fronts[i]

        min_ = inf
        for num in backs:
            if num not in frontSet and num < min_:
                min_ = num
        
        return min_ if min_ != inf else 0
