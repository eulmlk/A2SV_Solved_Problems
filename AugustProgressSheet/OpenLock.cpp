#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        unordered_set<string> deads(deadends.begin(), deadends.end());
        if (deads.count("0000"))
            return -1;

        unordered_set<string> visited;
        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        int step = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string cur = q.front();
                q.pop();

                if (cur == target)
                    return step;

                for (auto child : getChildren(cur)) {
                    if (!deads.count(child) && !visited.count(child)) {
                        q.push(child);
                        visited.insert(child);
                    }
                }
            }
            ++step;
        }

        return -1;
    }

private:
    vector<string> getChildren(string &str) {
        vector<string> result;

        for (int i = 0; i < str.length(); ++i) {
            char ch = str[i];

            char next = ch + 1;
            next = next > '9' ? '0' : next;
            char prev = ch - 1;
            prev = prev < '0' ? '9' : prev;

            str[i] = next;
            result.push_back(str);

            str[i] = prev;
            result.push_back(str);

            str[i] = ch;
        }

        return result;
    }
};