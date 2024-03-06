class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n, m = len(matrix), len(matrix[0])
        left, right = 0, n * m - 1

        while left <= right:
            mid = (left + right) // 2

            r, c = mid // m, mid % m
            if matrix[r][c] == target:
                return True
            
            if matrix[r][c] < target:
                left = mid + 1
            else:
                right = mid -1
        
        return False