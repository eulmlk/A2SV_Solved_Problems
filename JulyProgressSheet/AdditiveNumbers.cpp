#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((i > 1 && num[0] == '0') || (j - i > 1 && num[i] == '0')) {
                    break;
                }

                string a = num.substr(0, i);
                string b = num.substr(i, j - i);
                string rest = num.substr(j);
                if (isAdditiveNumberHelper(a, b, rest)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool isAdditiveNumberHelper(string a, string b, string rest) {
        if (rest.empty()) {
            return true;
        }

        string sum_ab = to_string(stol(a) + stol(b));
        if (rest.find(sum_ab) != 0) {
            return false;
        }

        return isAdditiveNumberHelper(b, sum_ab, rest.substr(sum_ab.length()));
    }
};

int main() {
    Solution solution;

    cout << solution.isAdditiveNumber("1023") << endl;
    // cout << solution.isAdditiveNumber("112358") << endl;
    // cout << solution.isAdditiveNumber("199100199") << endl;
    // cout << solution.isAdditiveNumber("234568113181") << endl;
}