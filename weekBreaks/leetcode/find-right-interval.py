class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        n = len(intervals)
        starts = [(intervals[i][0], i) for i in range(n)]
        starts.sort()

        result = []
        for i in range(n):
            target = intervals[i][1]
            left, right = 0, n - 1

            while left <= right:
                mid = (left + right) // 2
            
                if starts[mid][0] < target:
                    left = mid + 1
                else:
                    right = mid - 1
            
            if left < n:
                result.append(starts[left][1])
            else:
                result.append(-1)
        
        return result
