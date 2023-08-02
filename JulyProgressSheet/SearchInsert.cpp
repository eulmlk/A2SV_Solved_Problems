#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return left;
    }
};

int main() {
    Solution solution;

    vector<int> v = {1, 3, 5, 6};

    cout << solution.searchInsert(v, 5) << endl;
    cout << solution.searchInsert(v, 2) << endl;
    cout << solution.searchInsert(v, 7) << endl;
}