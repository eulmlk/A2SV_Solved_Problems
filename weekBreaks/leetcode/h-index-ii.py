class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        def isCited(h):
            i = bisect_left(citations, h)
            return n - i >= h
        
        left, right = 1, n
        while left <= right:
            mid = (left + right) // 2

            if isCited(mid):
                left = mid + 1
            else:
                right = mid - 1
        
        return right

