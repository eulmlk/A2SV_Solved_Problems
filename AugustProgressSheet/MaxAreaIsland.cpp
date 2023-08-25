#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        n = grid.size(), m = grid[0].size();
        this->grid = &grid;
        visited = vector<vector<bool>>(n, vector<bool>(m, false));

        int area = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] && !visited[i][j]) {
                    area = max(area, getArea(i, j));
                }
            }
        }

        return area;
    }

private:
    int getArea(int i, int j) {
        list<pair<int, int>> stack;
        stack.emplace_back(i, j);
        int area = 0;

        while (!stack.empty()) {
            auto [r, c] = stack.back();
            stack.pop_back();
            visited[r][c] = true;
            ++area;

            if (r + 1 < n && (*grid)[r + 1][c] && !visited[r + 1][c]) {
                stack.emplace_back(r + 1, c);
                visited[r + 1][c] = true;
            }

            if (r - 1 >= 0 && (*grid)[r - 1][c] && !visited[r - 1][c]) {
                stack.emplace_back(r - 1, c);
                visited[r - 1][c] = true;
            }

            if (c + 1 < m && (*grid)[r][c + 1] && !visited[r][c + 1]) {
                stack.emplace_back(r, c + 1);
                visited[r][c + 1] = true;
            }

            if (c - 1 >= 0 && (*grid)[r][c - 1] && !visited[r][c - 1]) {
                stack.emplace_back(r, c - 1);
                visited[r][c - 1] = true;
            }
        }

        return area;
    }

private:
    vector<vector<int>> *grid;
    vector<vector<bool>> visited;
    int n, m;
};