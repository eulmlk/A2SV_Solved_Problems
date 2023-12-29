class Solution {
public:
    string sortSentence(string s) {
        stringstream ss(s);
        vector<pair<int, string>> words;
        string cur;

        while (ss >> cur) {
            int order = cur.back();
            cur.pop_back();
            words.emplace_back(order, cur);
        }

        sort(words.begin(), words.end());

        string result;
        for (auto &[order, word] : words)
            result += word + ' ';
        
        result.pop_back();
        return result;
    }
};