class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(reverse=True)
        
        leftMost = points[0][0]
        arrows = 1

        for point in points:
            if point[1] < leftMost:
                arrows += 1
                leftMost = point[0]
        
        return arrows