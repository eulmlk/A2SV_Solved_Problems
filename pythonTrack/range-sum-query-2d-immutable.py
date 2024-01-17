class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        n, m = len(matrix), len(matrix[0])
        self.prefix = [[0 for _ in range(m)] for _ in range(n)]

        self.prefix[0][0] = matrix[0][0]
        for i in range(1, n):
            self.prefix[i][0] = self.prefix[i - 1][0] + matrix[i][0]

        for i in range(1, m):
            self.prefix[0][i] = self.prefix[0][i - 1] + matrix[0][i]

        for i in range(1, n):
            for j in range(1, m):
                self.prefix[i][j] = self.prefix[i][j - 1] + self.prefix[i - 1][j] - self.prefix[i - 1][j - 1] + matrix[i][j]


    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        if row1 == 0:
            if col1 == 0:
                return self.prefix[row2][col2]
            else:
                return self.prefix[row2][col2] - self.prefix[row2][col1 - 1]
        else:
            if col1 == 0:
                return self.prefix[row2][col2] - self.prefix[row1 - 1][col2]
            else:
                return self.prefix[row2][col2] - self.prefix[row2][col1 - 1] - self.prefix[row1 - 1][col2] + self.prefix[row1 - 1][col1 - 1]
        
        


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)