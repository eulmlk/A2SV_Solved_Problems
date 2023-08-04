#include <bits/stdc++.h>

using namespace std;

#define U64 unsigned long long

class Solution {
public:
    bool splitString(string s) {
        return isSplitValid(s, 0, 0, 0);
    }

private:
    bool isSplitValid(string s, int start, U64 prev, int count) {
        int n = s.length();
        if (start == n)
            return count > 1;

        U64 cur = 0;
        for (int i = start; i < n; ++i) {
            cur = cur * 10 + (s[i] - '0');

            if (prev - cur == 1 || start == 0) {
                if (isSplitValid(s, i + 1, cur, count + 1))
                    return true;
            }
        }

        return false;
    }
};

int main() {
    Solution solution;

    cout << solution.splitString("1234") << endl;
    cout << solution.splitString("050043") << endl;
    cout << solution.splitString("9080701") << endl;
    cout << solution.splitString("64424509442147483647") << endl;

    return 0;
}