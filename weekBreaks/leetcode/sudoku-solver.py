class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        rows = [[False] * 9 for _ in range(9)]
        cols = [[False] * 9 for _ in range(9)]
        boxes = [[False] * 9 for _ in range(9)]

        def getBox(i, j):
            x, y = i // 3, j // 3
            return x + 3 * y
        
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    continue
                
                rows[i][int(board[i][j]) - 1] = True
                cols[j][int(board[i][j]) - 1] = True
                boxes[getBox(i, j)][int(board[i][j]) - 1] = True

        def isInRow(row, num):
            return rows[row][num - 1]
        
        def isInCol(col, num):
            return cols[col][num - 1]
        
        def isInBox(box, num):
            return boxes[box][num - 1]
        
        def solve(i, j):
            if i == 9:
                return True
            
            if j == 9:
                return solve(i + 1, 0)
            
            if board[i][j] != '.':
                return solve(i, j + 1)
            
            box = getBox(i, j)
            for num in '123456789':
                if isInRow(i, int(num)) or isInCol(j, int(num)) or isInBox(box, int(num)):
                    continue
                
                board[i][j] = num
                rows[i][int(num) - 1] = True
                cols[j][int(num) - 1] = True
                boxes[box][int(num) - 1] = True
                if solve(i, j + 1):
                    return True

                board[i][j] = '.'
                rows[i][int(num) - 1] = False
                cols[j][int(num) - 1] = False
                boxes[box][int(num) - 1] = False

            return False
        
        solve(0, 0)
