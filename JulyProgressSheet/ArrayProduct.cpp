#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        vector<int> out(n, 1);

        int product = 1;
        for (int i = 1; i < n; ++i) {
            product *= nums[i - 1];
            out[i] *= product;
        }

        product = 1;
        for (int i = n - 2; i > -1; --i) {
            product *= nums[i + 1];
            out[i] *= product;
        }

        return out;
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
    vector<int> v2 = {-1, 1, 0, -3, 3};

    printVector(solution.productExceptSelf(v1));
    printVector(solution.productExceptSelf(v2));
}