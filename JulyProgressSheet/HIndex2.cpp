#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hIndex(vector<int> &citations) {
        int left = 0, right = 1000;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (isHIndex(citations, mid))
                left = mid + 1;
            else
                right = mid - 1;
        }

        return left;
    }

public:
    bool isHIndex(vector<int> &citations, int h) {
        int n = citations.size(), left = 0, right = n - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (citations[mid] >= h)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return n - left >= h;
    }
};

int main() {
    Solution solution;

    vector<int> v1 = {0, 1, 3, 5, 6};
    vector<int> v2 = {1, 2, 100};

    cout << solution.hIndex(v1) << endl;
    cout << solution.hIndex(v2) << endl;

    return 0;
}