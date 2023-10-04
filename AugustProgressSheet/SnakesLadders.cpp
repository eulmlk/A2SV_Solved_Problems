#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size();
        vector<int> flatBoard(n * n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            if ((n - 1 - i) % 2 == 0) {
                for (int j = 0; j < n; ++j)
                    flatBoard[i * n + j + 1] = board[n - i - 1][n - j - 1];

            } else {
                for (int j = n - 1; j >= 0; --j)
                    flatBoard[i * n + n - j] = board[n - i - 1][n - j - 1];
            }
        }

        for (int val : flatBoard)
            cout << val << " ";
        cout << endl;

        queue<int> q;
        vector<int> visited(n * n + 1, false);
        q.push(1);
        visited[1] = true;
        int moves = 0;

        while (!q.empty()) {
            int k = q.size();

            while (k--) {
                int cur = q.front();
                q.pop();

                cout << cur << endl;

                if (cur == n * n)
                    return moves;

                for (int j = 1; j <= 6 && cur + j <= n * n; ++j) {
                    int next = flatBoard[cur + j] == -1 ? cur + j : flatBoard[cur + j];

                    if (!visited[next]) {
                        q.push(next);
                        visited[next] = true;
                    }
                }
            }

            ++moves;
        }

        return -1;
    }
};