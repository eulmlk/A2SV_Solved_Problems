#include <bits/stdc++.h>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        rows = matrix.size() + 1;
        cols = matrix[0].size() + 1;

        int *mainSums = new int[cols];

        numbs = new int *[rows];
        for (int i = 0; i < rows; ++i) {
            numbs[i] = new int[cols];
            numbs[i][0] = 0;
        }

        memset(mainSums, 0, cols * sizeof(int));
        memset(numbs[0], 0, cols * sizeof(int));

        for (int i = 1; i < rows; ++i) {
            int sum = 0;
            for (int j = 1; j < cols; ++j) {
                sum += matrix[i - 1][j - 1];
                mainSums[j] += sum;

                numbs[i][j] = mainSums[j];
            }
        }

        delete[] mainSums;
    }

    ~NumMatrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] numbs[i];
        }
        delete[] numbs;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum1 = numbs[row2 + 1][col2 + 1] - numbs[row2 + 1][col1];
        int sum2 = numbs[row1][col2 + 1] - numbs[row1][col1];

        return sum1 - sum2;
    }

private:
    int **numbs;
    int rows, cols;
};

int main() {
    vector<vector<int>> m = {{3, 0, 1, 4, 2},
                             {5, 6, 3, 2, 1},
                             {1, 2, 0, 1, 5},
                             {4, 1, 0, 1, 7},
                             {1, 0, 3, 0, 5}};

    NumMatrix *obj = new NumMatrix(m);

    cout << obj->sumRegion(2, 1, 4, 3) << endl;
    cout << obj->sumRegion(1, 1, 2, 2) << endl;
    cout << obj->sumRegion(1, 2, 2, 4) << endl;

    delete obj;
}