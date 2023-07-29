#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> prefixSumModK(k, 0);
        int count = 0, currentSum = 0;

        for (int i = 0; i < n; ++i) {
            currentSum = (currentSum + nums[i]) % k;
            if (currentSum < 0)
                currentSum += k;

            count += prefixSumModK[currentSum];
            if (currentSum == 0)
                ++count;

            ++prefixSumModK[currentSum];
        }

        return count;
    }
};

int main() {
    Solution solution;

    vector<int> v1 = {4, 5, 0, -2, -3, 1};
    vector<int> v2 = {5};

    cout << solution.subarraysDivByK(v1, 5) << endl;
    cout << solution.subarraysDivByK(v2, 9) << endl;
}