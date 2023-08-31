#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
        n = grid1.size(), m = grid1[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;

        this->grid1 = &grid1;
        this->grid2 = &grid2;
        this->visited = &visited;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1 && !visited[i][j])
                    count += dfs(i, j);
            }
        }

        return count;
    }

private:
    int dfs(int i, int j) {
        stack<pair<int, int>> stk;
        stk.emplace(i, j);
        (*visited)[i][j] = true;
        int flag = 1;

        while (!stk.empty()) {
            auto [r, c] = stk.top();
            stk.pop();

            if ((*grid1)[r][c] == 0)
                flag = 0;

            for (int k = 0; k < 4; k++) {
                int x = r + dirs[k][0], y = c + dirs[k][1];

                if (x >= 0 && x < n && y >= 0 && y < m && (*grid2)[x][y] == 1 && !(*visited)[x][y]) {
                    stk.emplace(x, y);
                    (*visited)[x][y] = true;
                }
            }
        }

        return flag;
    }

private:
    int n, m;
    vector<vector<int>> *grid1, *grid2;
    vector<vector<bool>> *visited;

    static constexpr int dirs[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}};
};