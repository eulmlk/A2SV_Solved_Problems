class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        n, m = len(mat), len(mat[0])
        result = []

        i, j = 0, 0
        downward = False
        
        for _ in range(n * m):
            result.append(mat[i][j])

            if downward:
                if i == n - 1 and j == 0:
                    j += 1
                    downward = False
                elif i == n - 1:
                    j += 1
                    downward = False
                elif j == 0:
                    i += 1
                    downward = False
                else:
                    i += 1
                    j -= 1
            else:
                if i == 0 and j == m - 1:
                    i += 1
                    downward = True
                elif i == 0:
                    j += 1
                    downward = True
                elif j == m - 1:
                    i += 1
                    downward = True
                else:
                    i -= 1
                    j += 1
                    
        return result
