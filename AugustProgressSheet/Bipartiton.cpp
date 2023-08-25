#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
        graph = vector<list<int>>(n);
        color = vector(n, -1);

        for (auto &d : dislikes) {
            graph[d[0] - 1].push_back(d[1] - 1);
            graph[d[1] - 1].push_back(d[0] - 1);
        }

        for (int i = 0; i < n; i++) {
            if (color[i] != -1)
                continue;

            if (!isBipartite(i))
                return false;
        }

        return true;
    }

private:
    bool isBipartite(int i) {
        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            int node = q.front();
            int col = color[node];
            q.pop();

            for (int neighbor : graph[node]) {
                if (color[neighbor] == -1) {
                    color[neighbor] = 3 - col;
                    q.push(neighbor);
                } else if (color[neighbor] == col) {
                    return false;
                }
            }
        }

        return true;
    }

private:
    vector<list<int>> graph;
    vector<int> color;
};

int main() {
    return 0;
}