class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        n, m = len(board), len(board[0])
        k = len(word)

        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]

        def find(row, col, ind, visited):
            if row < 0 or row >= n or col < 0 or col >= m:
                return False
            
            if board[row][col] != word[ind]:
                return False
            
            if ind == k - 1:
                return True
            
            for dr, dc in dirs:
                nextRow, nextCol = row + dr, col + dc

                if (nextRow, nextCol) in visited:
                    continue
                
                visited.add((nextRow, nextCol))
                if find(nextRow, nextCol, ind + 1, visited):
                    return True
                
                visited.remove((nextRow, nextCol))
            
            return False
        
        for i in range(n):
            for j in range(m):
                if find(i, j, 0, set([(i, j)])):
                    return True
        
        return False