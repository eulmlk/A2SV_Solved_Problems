#include <bits/stdc++.h>

using namespace std;

class Solution {

public:
    void solve(vector<vector<char>> &board) {
        n = board.size(), m = board[0].size();
        this->board = &board;

        if (n == 0)
            return;

        for (int i = 0; i < n; ++i) {
            if (board[i][0] == 'O')
                dfs(i, 0);

            if (board[i][m - 1] == 'O')
                dfs(i, m - 1);
        }

        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O')
                dfs(0, i);

            if (board[n - 1][i] == 'O')
                dfs(n - 1, i);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }

private:
    void dfs(int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m || (*board)[x][y] != 'O')
            return;

        (*board)[x][y] = '#';

        dfs(x + 1, y);
        dfs(x - 1, y);
        dfs(x, y + 1);
        dfs(x, y - 1);
    }

private:
    int n, m;
    vector<vector<char>> *board;
};