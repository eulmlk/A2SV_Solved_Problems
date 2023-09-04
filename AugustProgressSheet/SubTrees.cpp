#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels) {
        vector<vector<int>> adj(n);
        vector<int> result(n, 0);

        this->adj = &adj;
        this->result = &result;
        this->labels = &labels;

        for (int i = 0; i != edges.size(); ++i) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        dfs(0);
        return result;
    }

private:
    vector<int> dfs(int i) {
        vector<int> ans(26, 0);
        ans[(*labels)[i] - 'a'] = 1;
        (*result)[i] = 1;

        for (int j = 0; j != (*adj)[i].size(); ++j)
            if (!(*result)[(*adj)[i][j]]) {
                vector<int> tmp = dfs((*adj)[i][j]);
                for (int k = 0; k != 26; k++)
                    ans[k] += tmp[k];
            }

        (*result)[i] = ans[(*labels)[i] - 'a'];

        return ans;
    }

private:
    vector<vector<int>> *adj;
    vector<int> *result;
    string *labels;
};