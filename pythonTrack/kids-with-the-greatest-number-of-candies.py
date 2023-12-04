class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        maxCandies = max(candies)
        canHave = [False] * len(candies)

        for ind, candy in enumerate(candies):
            if candy + extraCandies >= maxCandies:
                canHave[ind] = True
        
        return canHave