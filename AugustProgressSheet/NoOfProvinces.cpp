#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, 0);
        int provinces = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++provinces;
                search(isConnected, visited, i);
            }
        }
        return provinces;
    }

private:
    void search(vector<vector<int>> &isConnected, vector<bool> &visited, int i) {
        list<int> stack;
        stack.push_back(i);

        while (!stack.empty()) {
            int val = stack.back();
            stack.pop_back();
            visited[val] = true;

            for (int j = 0, n = isConnected.size(); j < n; ++j) {
                if (!visited[j] && isConnected[val][j]) {
                    stack.push_back(j);
                    visited[j] = true;
                }
            }
        }
    }
};