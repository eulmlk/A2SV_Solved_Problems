#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        powerSet.clear();
        sub.clear();

        powerSet.push_back(sub);

        enumerateSubsets(nums, 0);

        return powerSet;
    }

private:
    void enumerateSubsets(vector<int> &nums, int index) {
        int n = nums.size();
        if (index == n)
            return;

        sub.push_back(nums[index]);
        powerSet.push_back(sub);

        for (int i = index + 1; i < n; ++i) {
            sub.push_back(nums[i]);

            powerSet.push_back(sub);

            enumerateSubsets(nums, i + 1);
            sub.pop_back();
        }

        sub.pop_back();
        enumerateSubsets(nums, index + 1);
    }

private:
    vector<vector<int>> powerSet;
    vector<int> sub;
};

void printVector(vector<int> &v) {
    cout << "[ ";
    for (auto val : v) {
        cout << val << " ";
    }
    cout << "]\n";
}

void printVector(vector<vector<int>> powerSet) {
    cout << "[\n";
    for (auto val : powerSet) {
        cout << "    ";
        printVector(val);
    }
    cout << "]\n";
}

int main() {
    Solution solution;

    vector<int> v1 = {0};
    vector<int> v2 = {1, 2, 3};

    printVector(solution.subsets(v1));
    printVector(solution.subsets(v2));
}