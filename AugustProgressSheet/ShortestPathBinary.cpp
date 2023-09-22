#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        int len = 1;

        if (grid[0][0] || grid[n - 1][m - 1])
            return -1;

        queue<pair<int, int>> q;
        unordered_set<int> visited;
        q.emplace(0, 0);
        visited.insert(0);

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [i, j] = q.front();
                q.pop();

                if (i == n - 1 && j == m - 1)
                    return len;

                for (auto [dx, dy] : dirs) {
                    int x = i + dx, y = j + dy;

                    if (x < 0 || x >= n || y < 0 || y >= m || visited.count(x * m + y) || grid[x][y])
                        continue;

                    visited.insert(x * m + y);
                    q.emplace(x, y);
                }
            }
            ++len;
        }

        return -1;
    }

private:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
};