#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        s = getAlphaNumeric(s);

        return checkPalindrome(s, 0, s.length() - 1);
    }

private:
    string getAlphaNumeric(const string &s) {
        string out;
        out.reserve(s.length());

        for (char ch : s) {
            char lowerCh = tolower(ch);
            if (isalnum(lowerCh))
                out += lowerCh;
        }

        return out;
    }

    bool checkPalindrome(const string &s, int first, int last) {
        if (first > last)
            return true;

        if (s[first] != s[last])
            return false;

        return checkPalindrome(s, first + 1, last - 1);
    }
};

int main() {
    Solution solution;

    cout << solution.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << solution.isPalindrome("race a car") << endl;
    cout << solution.isPalindrome(" ") << endl;
}