class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        n = len(grid)

        skylineR = []
        skylineC = []

        for row in grid:
            skylineR.append(max(row))
        
        gridT = [[grid[j][i] for j in range(n)] for i in range(n)]

        for col in gridT:
            skylineC.append(max(col))

        total = 0

        for i in range(n):
            for j in range(n):
                total += min(skylineR[i], skylineC[j]) - grid[i][j]

        return total