#include <iostream>
#include <list>
#include <vector>

using namespace std;

void addEdge(vector<list<int>> &adjacency, int u, int v) {
    adjacency[u].insert(lower_bound(adjacency[u].begin(), adjacency[u].end(), v), v);
    adjacency[v].insert(lower_bound(adjacency[v].begin(), adjacency[v].end(), u), u);
}

void printGraph(const vector<list<int>> &adjacency, int v) {
    bool printed = false;
    for (int i : adjacency[v]) {
        printed = true;
        cout << i + 1 << ' ';
    }

    if (printed)
        cout << '\n';
}

int main() {
    int n;

    cin >> n;

    vector<list<int>> adjacency(n);

    int q;

    cin >> q;

    while (q--) {
        int oper;

        cin >> oper;

        if (oper == 1) {
            int u, v;
            cin >> u >> v;
            addEdge(adjacency, u - 1, v - 1);
        } else {
            int v;
            cin >> v;
            printGraph(adjacency, v - 1);
        }
    }

    return 0;
}
