#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts) {
        int n = s.size();
        vector<long long> prefixSum(n, 0);

        for (int i = shifts.size() - 1; i >= 0; --i) {
            int start = shifts[i][0], end = shifts[i][1];
            long long shift = 2 * shifts[i][2] - 1;

            prefixSum[start] += shift;
            if (end + 1 < n)
                prefixSum[end + 1] -= shift;
        }

        long long totalShift = 0;
        for (int i = 0; i < n; ++i) {
            totalShift = (totalShift + prefixSum[i]) % 26;
            s[i] = 'a' + (s[i] - 'a' + totalShift + 26) % 26;
        }

        return s;
    }
};
