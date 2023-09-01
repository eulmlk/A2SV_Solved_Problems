#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

bool isBipartite(const vector<list<int>> &graph, vector<int> &color, int i) {
    queue<int> q;
    q.push(i);
    color[i] = 1;

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

void addEdge(vector<list<int>> &graph, int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

int main() {
    int n;

    while (true) {
        cin >> n;
        if (n == 0)
            break;

        vector<list<int>> graph(n);
        vector<int> color(n, -1);

        int m, u, v;
        cin >> m;

        while (m--) {
            cin >> u >> v;
            addEdge(graph, u - 1, v - 1);
        }

        bool isBicolorable = true;
        for (int i = 0; i < n; ++i) {
            if (color[i] != -1)
                continue;

            if (!isBipartite(graph, color, i)) {
                cout << "NOT BICOLOURABLE." << endl;
                isBicolorable = false;
                break;
            }
        }

        if (isBicolorable)
            cout << "BICOLOURABLE." << endl;
    }

    return 0;
}