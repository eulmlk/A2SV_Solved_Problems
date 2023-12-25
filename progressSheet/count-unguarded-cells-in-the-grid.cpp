class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(m, vector(n, '.'));

        for (const auto& wall : walls) {
            int row = wall[0], col = wall[1];
            grid[row][col] = 'W';
        }

        for (const auto& guard : guards) {
            int row = guard[0], col = guard[1];
            grid[row][col] = 'G';
        }
        
        for (const auto& guard : guards) {
            int row = guard[0], col = guard[1];
            grid[row][col] = 'G';

            for (int i = row; i >= 0; --i) {
                if (grid[i][col] == 'W' || (grid[i][col] == 'G' && i != row))
                    break;
                
                if (grid[i][col] == '.')
                    grid[i][col] = 'M';
            }

            for (int i = row; i < m; ++i) {
                if (grid[i][col] == 'W' || (grid[i][col] == 'G' && i != row))
                    break;
                
                if (grid[i][col] == '.')
                    grid[i][col] = 'M';
            }

            for (int j = col; j >= 0; --j) {
                if (grid[row][j] == 'W' || (grid[row][j] == 'G' && j != col))
                    break;
                
                if (grid[row][j] == '.')
                    grid[row][j] = 'M';
            }

            for (int j = col; j < n; ++j) {
                if (grid[row][j] == 'W' || (grid[row][j] == 'G' && j != col))
                    break;
                
                if (grid[row][j] == '.')
                    grid[row][j] = 'M';
            }
        }

        int unguarded = 0;
        for (const auto& row : grid) {
            for (char val : row) {
                if (val == '.')
                    ++unguarded;
            }
        }

        return unguarded;
    }
};