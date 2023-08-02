#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSumRangeQuery(vector<int> &nums, vector<vector<int>> &requests) {
        int size = nums.size();
        int counts[size + 1];
        memset(counts, 0, (size + 1) * sizeof(int));
        vector<int> prefixSums;
        prefixSums.reserve(size);

        for (int i = 0, n = requests.size(); i < n; ++i) {
            ++counts[requests[i][0]];
            --counts[requests[i][1] + 1];
        }

        int sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += counts[i];
            prefixSums.push_back(sum);
        }

        sort(nums.rbegin(), nums.rend());
        sort(prefixSums.rbegin(), prefixSums.rend());

        long long maxSum = 0;
        for (int i = 0; i < size; ++i) {
            maxSum += (long)nums[i] * (long)prefixSums[i];
        }

        return (int)(maxSum % 1'000'000'007LL);
    }
};

int main() {
    Solution solution;

    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {1, 2, 3, 4, 5, 6};
    vector<int> v3 = {1, 2, 3, 4, 5, 10};

    vector<vector<int>> r1 = {{1, 3}, {0, 1}};
    vector<vector<int>> r2 = {{0, 1}};
    vector<vector<int>> r3 = {{0, 2}, {1, 3}, {1, 1}};

    cout << solution.maxSumRangeQuery(v1, r1) << endl;
    cout << solution.maxSumRangeQuery(v2, r2) << endl;
    cout << solution.maxSumRangeQuery(v3, r3) << endl;

    return 0;
}