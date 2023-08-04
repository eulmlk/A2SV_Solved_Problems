#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals) {
        vector<int> rights;
        int n = intervals.size();
        rights.reserve(n);
        int inters[n];
        for (int i = 0; i < n; ++i) {
            inters[i] = intervals[i][1];
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end(),
             [&](const vector<int> &v1, const vector<int> &v2) { return v1[0] < v2[0]; });

        for (auto target : inters) {
            int left = 0, right = n - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (intervals[mid][0] >= target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }

            if (left >= n)
                rights.push_back(-1);
            else
                rights.push_back(intervals[left][2]);
        }

        return rights;
    }
};

void printVector(vector<int> &&v) {
    cout << "[ ";
    for (auto val : v) {
        cout << val << "  ";
    }
    cout << "]\n";
}

int main() {
    Solution solution;

    vector<vector<int>> v1 = {{1, 2}};
    vector<vector<int>> v2 = {{3, 4}, {2, 3}, {1, 2}};
    vector<vector<int>> v3 = {{1, 4}, {2, 3}, {3, 4}};

    printVector(solution.findRightInterval(v1));
    printVector(solution.findRightInterval(v2));
    printVector(solution.findRightInterval(v3));

    return 0;
}