class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        board = [['.'] * n for _ in range(n)]

        rows = [False] * n
        cols = [False] * n
        diags1 = defaultdict(bool)
        diags2 = defaultdict(bool)

        result = []
        def solve(i, j, queens):
            if i == n:
                if queens == n:
                    result.append([''.join(row) for row in board])
                
                return
            
            if j == n:
                solve(i + 1, 0, queens)
                return
            
            if rows[i] or cols[j] or diags1[i + j] or diags2[i - j]:
                solve(i, j + 1, queens)
                return
            
            board[i][j] = 'Q'
            rows[i] = True
            cols[j] = True
            diags1[i + j] = True
            diags2[i - j] = True

            solve(i, j + 1, queens + 1)

            board[i][j] = '.'
            rows[i] = False
            cols[j] = False
            diags1[i + j] = False
            diags2[i - j] = False

            solve(i, j + 1, queens)

        solve(0, 0, 0)
        return result