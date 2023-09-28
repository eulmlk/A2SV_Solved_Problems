#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    q.emplace(i, j);
                    dist[i][j] = 0;
                }
            }
        }

        int count = 1;
        while (!q.empty()) {
            int qn = q.size();

            while (qn--) {
                auto [r, c] = q.front();
                q.pop();

                for (auto &[dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;

                    if (x >= 0 && x < n && y >= 0 && y < m && dist[x][y] == -1 && mat[x][y] == 1)
                        q.emplace(x, y), dist[x][y] = count;
                }
            }

            ++count;
        }

        return dist;
    }

private:
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};
