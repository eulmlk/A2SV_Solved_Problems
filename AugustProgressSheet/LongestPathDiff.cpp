#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestPath(vector<int> &parent, string s) {
        vector<vector<int>> a(parent.size());

        for (int i = 1; i < parent.size(); ++i)
            a[parent[i]].push_back(i);

        dfs(0, a, s);

        return maxPath + 1;
    }

private:
    int dfs(int root, vector<vector<int>> &a, string &s) {
        int maxPath1 = 0;
        int maxPath2 = 0;

        for (int child : a[root]) {
            int pathlength = dfs(child, a, s);
            pathlength = s[child] == s[root] ? 0 : pathlength + 1;

            if (pathlength >= maxPath1) {
                maxPath2 = maxPath1;
                maxPath1 = pathlength;
            } else if (pathlength >= maxPath2) {
                maxPath2 = pathlength;
            }
        }
        maxPath = max(maxPath, maxPath1 + maxPath2);

        return maxPath1;
    }

private:
    int maxPath = 0;
};