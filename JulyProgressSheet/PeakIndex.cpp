#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int> &arr) {
        int left = 0, right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] > arr[mid + 1])
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }
};

int main() {
    Solution solution;

    vector<int> v1 = {0, 1, 0};
    vector<int> v2 = {0, 2, 1, 0};
    vector<int> v3 = {0, 10, 5, 2};
    vector<int> v4 = {0, 2, 3, 4, 5, 6, 10, 7, 5, 2};

    cout << solution.peakIndexInMountainArray(v1) << endl;
    cout << solution.peakIndexInMountainArray(v2) << endl;
    cout << solution.peakIndexInMountainArray(v3) << endl;
    cout << solution.peakIndexInMountainArray(v4) << endl;

    return 0;
}