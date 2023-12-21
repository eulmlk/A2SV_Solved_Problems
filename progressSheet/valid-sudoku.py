class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        def isValid(row: int, col: int) -> bool:
            boxRow = 3 * (row // 3)
            boxCol = 3 * (col // 3)

            for index in range(9):
                if index == col or board[row][index] == '.':
                    continue
                
                if board[row][index] == board[row][col]:
                    return False
            
            for index in range(9):
                if index == row or board[index][col] == '.':
                    continue
                
                if board[index][col] == board[row][col]:
                    return False
            
            for x in range(3):
                for y in range(3):
                    r = boxRow + x
                    c = boxCol + y

                    if r == row and c == col or board[r][c] == '.':
                        continue
                    
                    if board[r][c] == board[row][col]:
                        return False
            
            return True
                

        for row in range(9):
            for col in range(9):
                if not isValid(row, col):
                    return False
        
        return True