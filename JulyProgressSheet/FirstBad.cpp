#include <bits/stdc++.h>

using namespace std;

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

#define SAMPLE_FIRST_BAD 7600
#define SAMPLE_N 50000

class Solution {
public:
    int firstBadVersion(int n) {
        int mid = -1, left = 0, right = n;

        while (left <= right) {
            mid = left + (right - left) / 2;

            if (isBadVersion(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};

bool isBadVersion(int version) {
    return version >= SAMPLE_FIRST_BAD;
}

int main() {
    Solution solution;

    cout << solution.firstBadVersion(SAMPLE_N) << endl;

    return 0;
}