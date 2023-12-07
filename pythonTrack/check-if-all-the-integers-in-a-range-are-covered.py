class Solution:
    def isCovered(self, ranges: List[List[int]], left: int, right: int) -> bool:
        givenRange = {i for i in range(left, right + 1)}
        totalRange = set()

        for low, high in ranges:
            totalRange |= {i for i in range(low, high + 1)}
        
        return givenRange <= totalRange