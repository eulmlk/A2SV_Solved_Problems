class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        int masks[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        int bmasks[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

        for (int i = 0; i < 9; ++i) {
            int mask = 0;
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;

                int ind = 1 << (board[i][j] - '1');
                if (mask & ind)
                    return false;

                if (masks[j] & ind)
                    return false;

                int r = i / 3, c = j / 3;
                int b = r * 3 + c;

                if (bmasks[b] & ind)
                    return false;

                mask |= ind;
                masks[j] |= ind;
                bmasks[b] |= ind;
            }
        }

        return true;
    }
};