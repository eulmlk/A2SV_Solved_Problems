#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        paths.clear();
        path.clear();
        this->graph = &graph;

        search(0);

        return paths;
    }

    void search(int node) {
        path.push_back(node);

        if (node == graph->size() - 1) {
            paths.push_back(path);
        } else {
            for (int neighbor : (*graph)[node]) {
                search(neighbor);
            }
        }

        path.pop_back();
    }

private:
    vector<vector<int>> *graph;
    vector<vector<int>> paths;
    vector<int> path;
};