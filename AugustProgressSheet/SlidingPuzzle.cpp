#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>> &board) {
        typedef vector<vector<int>> Board;
        Board target = {{1, 2, 3}, {4, 5, 0}};

        if (board == target)
            return 0;

        set<Board> visited;
        queue<Board> q;
        q.push(board);
        visited.insert(board);
        int moves = 0;

        while (!q.empty()) {
            int k = q.size();

            while (k--) {
                auto cur = q.front();
                q.pop();

                if (cur == target)
                    return moves;

                int r = -1, c = -1;
                for (int i = 0; i < 2; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        if (cur[i][j] == 0)
                            r = i, c = j, i = 2, j = 3;
                    }
                }

                for (auto &[dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x >= 0 && x < 2 && y >= 0 && y < 3) {
                        swap(cur[x][y], cur[r][c]);
                        if (visited.find(cur) == visited.end()) {
                            q.push(cur);
                            visited.insert(cur);
                        }
                        swap(cur[x][y], cur[r][c]);
                    }
                }
            }

            ++moves;
        }

        return -1;
    }

private:
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};