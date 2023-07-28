#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int> &nums) {
        vector<int> running;
        int sum = 0;

        for (int i = 0, n = nums.size(); i < n; ++i) {
            sum += nums[i];
            running.push_back(sum);
        }

        return running;
    }
};

void printVector(vector<int> &&v) {
    cout << "[";
    for (auto val : v) {
        cout << val << "  ";
    }
    cout << "]\n";
}

int main() {
    Solution solution;

    vector<int> v1 = {1, 2, 3, 4};
    vector<int> v2 = {1, 1, 1, 1, 1};
    vector<int> v3 = {3, 1, 2, 10, 1};

    printVector(solution.runningSum(v1));
    printVector(solution.runningSum(v2));
    printVector(solution.runningSum(v3));
}