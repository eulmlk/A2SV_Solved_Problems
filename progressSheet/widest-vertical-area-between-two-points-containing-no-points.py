class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        points.sort()
        n = len(points)
        maxDiff = float('-inf')

        for i in range(n - 1):
            diff = abs(points[i][0] - points[i + 1][0])
            maxDiff = max(maxDiff, diff)

        return maxDiff