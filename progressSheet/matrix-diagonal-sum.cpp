class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int primary = 0, secondary = 0;

        for (int i = 0; i < n; ++i) {
            primary += mat[i][i];

            if (i != n - 1 - i)
                secondary += mat[n - 1 - i][i];
        }

        return primary + secondary;
    }
};