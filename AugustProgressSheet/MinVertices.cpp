#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges) {
        int counts[n];
        memset(counts, 0, sizeof(counts));

        for (auto &edge : edges)
            counts[edge[1]]++;

        vector<int> result;
        result.reserve(n);

        for (int i = 0; i < n; ++i) {
            if (counts[i] == 0)
                result.push_back(i);
        }

        return result;
    }
};

int main() {
    return 0;
}