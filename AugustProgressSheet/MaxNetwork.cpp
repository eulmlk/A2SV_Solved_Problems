#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads) {
        vector<int> degree(n, 0);
        set<pair<int, int>> adjacency;

        for (auto &road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
            adjacency.insert({road[0], road[1]});
        }

        int max = INT32_MIN, cur = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                cur = degree[i] + degree[j] - (adjacency.find({i, j}) != adjacency.end() || adjacency.find({j, i}) != adjacency.end());
                max = cur > max ? cur : max;
            }
        }

        return max;
    }
};

int main() {
    return 0;
}