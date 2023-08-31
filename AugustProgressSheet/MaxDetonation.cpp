#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumDetonation(vector<vector<int>> &bombs) {
        int n = bombs.size();
        vector<list<int>> adjacency(n, list<int>());

        for (int i = 0; i < n; ++i) {
            long long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            for (int j = 0; j < n; ++j) {
                if (i == j)
                    continue;

                long long x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
                long long dx = x2 - x1, dy = y2 - y1;

                if ((dx * dx) + (dy * dy) <= r1 * r1)
                    adjacency[i].push_back(j);
            }
        }

        int maxDeton = INT32_MIN;
        for (int i = 0; i < n; ++i) {
            maxDeton = max(maxDeton, dfs(adjacency, i));
        }

        return maxDeton;
    }

private:
    int dfs(vector<list<int>> &adjacency, int i) {
        vector<bool> visited(adjacency.size(), false);
        stack<int> nodes;
        nodes.push(i);
        visited[i] = true;

        int deton = 0;
        while (!nodes.empty()) {
            int node = nodes.top();
            nodes.pop();
            ++deton;

            for (int neighbor : adjacency[node]) {
                if (!visited[neighbor]) {
                    nodes.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        return deton;
    }
};

int main() {
    return 0;
}