class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto compare = [](const string &str1, const string &str2) {
            return str1 + str2 < str2 + str1;
        };

        vector<string> strs;

        for (int val : nums) 
            strs.push_back(to_string(val));
        
        sort(strs.rbegin(), strs.rend(), compare);

        string res;
        for (auto &str : strs) {
            if (res.empty() && str == "0")
                continue;

            res += str;
        }

        return res.empty() ? "0" : res;
    }
};