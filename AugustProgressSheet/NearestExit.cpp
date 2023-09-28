#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
        int n = maze.size(), m = maze[0].size();
        vector<vector<bool>> visited = vector(n, vector(m, false));
        queue<pair<int, int>> q;

        q.emplace(entrance[0], entrance[1]);
        visited[entrance[0]][entrance[1]] = true;

        int count = 0;
        while (!q.empty()) {
            int qn = q.size();

            while (qn--) {
                auto [r, c] = q.front();
                q.pop();

                if ((r != entrance[0] || c != entrance[1]) && maze[r][c] == '.') {
                    if (r == 0 || c == 0 || r == n - 1 || c == m - 1)
                        return count;
                }

                for (auto [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;

                    if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || maze[x][y] == '+')
                        continue;

                    visited[x][y] = true;
                    q.emplace(x, y);
                }
            }

            ++count;
        }

        return -1;
    }

private:
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};