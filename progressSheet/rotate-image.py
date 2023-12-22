class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        size = len(matrix)

        for row in range(size // 2):
            matrix[row], matrix[size - row - 1] = matrix[size - row - 1], matrix[row]

        for row in range(size):
            for col in range(row + 1, size):
                matrix[row][col], matrix[col][row] = matrix[col][row], matrix[row][col]
        