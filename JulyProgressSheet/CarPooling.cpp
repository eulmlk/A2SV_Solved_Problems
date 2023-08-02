#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>> &trips, int capacity) {
        int travels[1000];
        memset(travels, 0, 1000 * sizeof(int));

        for (int i = 0, n = trips.size(); i < n; ++i) {
            int numb = trips[i][0], from = trips[i][1], to = trips[i][2];

            travels[from] += numb;
            travels[to] += -numb;
        }

        int sum = 0;
        for (int i = 0; i < 1000; ++i) {
            sum += travels[i];

            if (sum > capacity) {
                cout << "Sum: " << sum << "\tCapacity: " << capacity << endl;
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> v1 = {{2, 1, 5}, {3, 3, 7}};
    vector<vector<int>> v2 = {{2, 4, 5}, {3, 3, 7}, {4, 1, 8}};
    vector<vector<int>> v3 = {{2, 1, 5}, {3, 5, 7}};

    cout << solution.carPooling(v1, 4) << endl;
    cout << solution.carPooling(v1, 5) << endl;
    cout << solution.carPooling(v2, 9) << endl;
    cout << solution.carPooling(v3, 3) << endl;
}