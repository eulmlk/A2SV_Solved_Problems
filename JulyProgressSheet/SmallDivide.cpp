#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int> &nums, int threshold) {
        int left = 0, right = 1'000'000;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (isValid(nums, threshold, mid))
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }

private:
    bool isValid(vector<int> &nums, int threshold, int divisor) {
        if (divisor < 1)
            return false;

        int sum = 0;

        for (auto val : nums) {
            sum += val / divisor;
            sum += val % divisor != 0;
        }

        return sum <= threshold;
    }
};

int main() {
    Solution solution;

    vector<int> v1 = {1, 2, 5, 9};
    vector<int> v2 = {44, 22, 33, 11, 1};
    vector<int> v3 = {21212, 10101, 12121};

    cout << solution.smallestDivisor(v1, 6) << endl;
    cout << solution.smallestDivisor(v2, 5) << endl;
    cout << solution.smallestDivisor(v3, 1000000) << endl;

    return 0;
}