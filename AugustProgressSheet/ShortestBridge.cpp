#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector(m, false));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    queue<pair<int, int>> q2;
                    q2.emplace(i, j);
                    q.emplace(i, j);
                    visited[i][j] = true;

                    while (!q2.empty()) {
                        auto [r, c] = q2.front();
                        q2.pop();

                        for (auto &[dr, dc] : dirs) {
                            int x = r + dr, y = c + dc;

                            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 && !visited[x][y]) {
                                q2.emplace(x, y);
                                q.emplace(x, y);
                                visited[x][y] = true;
                            }
                        }
                    }
                    i = n, j = m;
                }
            }
        }

        int dist = 0;
        while (!q.empty()) {
            for (int i = q.size(); i > 0; i--) {
                auto [r, c] = q.front();
                q.pop();
                for (auto &[dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;

                    if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y]) {
                        if (grid[x][y] == 0)
                            q.emplace(x, y), visited[x][y] = true;
                        else if (grid[x][y] == 1)
                            return dist;
                    }
                }
            }
            dist++;
        }

        return dist;
    }

private:
    vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
};