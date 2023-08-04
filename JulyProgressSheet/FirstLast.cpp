#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.empty())
            return v;

        vector<int> answer;

        answer.push_back(searchFirst(nums, target));
        answer.push_back(searchLast(nums, target));

        return answer;
    }

private:
    int searchFirst(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        if (left > nums.size() - 1)
            --left;
        return nums[left] == target ? left : -1;
    }

    int searchLast(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        if (left > 0)
            --left;
        return nums[left] == target ? left : -1;
    }

private:
    vector<int> v = {-1, -1};
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

    vector<int> v1 = {5, 7, 7, 8, 8, 10};
    vector<int> v2 = {};
    vector<int> v3 = {2, 2};

    printVector(solution.searchRange(v1, 8));
    printVector(solution.searchRange(v1, 6));
    printVector(solution.searchRange(v2, 0));
    printVector(solution.searchRange(v3, 3));

    return 0;
}