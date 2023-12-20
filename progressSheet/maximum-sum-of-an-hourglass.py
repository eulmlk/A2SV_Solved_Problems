class Solution:
    def maxSum(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        maxSum = float('-inf')

        for row in range(rows - 2):
            for col in range(cols - 2):
                curSum = grid[row][col] + grid[row][col + 1] + grid[row][col + 2]
                curSum += grid[row + 1][col + 1]
                curSum += grid[row + 2][col] + grid[row + 2][col + 1] + grid[row + 2][col + 2]

                maxSum = max(maxSum, curSum)
        
        return maxSum