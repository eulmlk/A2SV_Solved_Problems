class Solution {
public:
    bool isValid(string s) {
        string t = "";
        for (char ch : s) {
            if (ch == '[' || ch == '(' || ch == '{') {
                t += ch;
            } else if (ch == ']') {
                if (t.empty())
                    return false;

                if (t.back() != '[')
                    return false;
                else
                    t.pop_back();
            } else if (ch == ')') {
                if (t.empty())
                    return false;

                if (t.back() != '(')
                    return false;
                else
                    t.pop_back();
            } else if (ch == '}') {
                if (t.empty())
                    return false;

                if (t.back() != '{')
                    return false;
                else
                    t.pop_back();
            }
        }

        return t.empty();
    }
};