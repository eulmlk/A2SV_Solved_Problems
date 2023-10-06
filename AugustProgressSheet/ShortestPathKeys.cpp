#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestPathAllKeys(vector<string> &grid) {
        int n = grid.size(), m = grid[0].size();

        unordered_map<char, int> keyMasks;
        int bits = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (islower(grid[i][j]))
                    keyMasks[grid[i][j]] = bits++;
            }
        }

        int allKeysMask = (1 << bits) - 1;
        int keyCount = (1 << bits);

        vector<vector<vector<bool>>> visited(n, vector(m, vector(keyCount, false)));
        tuple<int, int, int> start;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '@')
                    start = {i, j, 0}, i = n, j = m;
            }
        }

        queue<tuple<int, int, int>> q;
        q.push(start);
        int step = 0;

        while (!q.empty()) {
            int k = q.size();

            while (k--) {
                auto [r, c, mask] = q.front();
                q.pop();

                if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == '#')
                    continue;

                if (isupper(grid[r][c])) {
                    if ((mask & (1 << keyMasks[tolower(grid[r][c])])) == 0)
                        continue;
                }

                if (islower(grid[r][c]))
                    mask = mask | (1 << keyMasks[grid[r][c]]);

                if (mask == allKeysMask)
                    return step;

                if (visited[r][c][mask])
                    continue;

                visited[r][c][mask] = true;

                q.emplace(r + 1, c, mask);
                q.emplace(r - 1, c, mask);
                q.emplace(r, c + 1, mask);
                q.emplace(r, c - 1, mask);
            }

            ++step;
        }

        return -1;
    }
};