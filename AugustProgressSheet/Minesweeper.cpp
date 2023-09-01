#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board,
                                     vector<int> &click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        n = board.size(), m = board[0].size();
        this->board = move(board);
        dfs(click[0], click[1]);
        return this->board;
    }

private:
    const vector<pair<int, int>> dirs{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    void dfs(int i, int j) {
        if (i < 0 || i == board.size() || j < 0 || j == board[0].size())
            return;

        if (board[i][j] != 'E')
            return;

        const int mines = getMinesCount(i, j);
        board[i][j] = mines == 0 ? 'B' : '0' + mines;

        if (mines == 0)
            for (const auto &[dx, dy] : dirs)
                dfs(i + dx, j + dy);
    }

    int getMinesCount(int i, int j) {
        int count = 0;
        for (const auto &[dx, dy] : dirs) {
            int x = i + dx, y = j + dy;

            if (x < 0 || x == board.size() || y < 0 || y == board[0].size())
                continue;
            if (board[x][y] == 'M')
                ++count;
        }
        return count;
    }

private:
    vector<vector<char>> board;
    int n, m;
};