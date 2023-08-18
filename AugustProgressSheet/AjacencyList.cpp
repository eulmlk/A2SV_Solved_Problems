#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    int adjacency[n][n];

    for (int i = 0; i < n; ++i) {
        int edges[n];
        int m = 0;

        for (int j = 0; j < n; ++j) {
            cin >> adjacency[i][j];

            if (adjacency[i][j] != 0)
                edges[m++] = j + 1;
        }

        cout << m << ' ';
        for (int j = 0; j < m; ++j)
            cout << edges[j] << ' ';
        cout << endl;
    }

    return 0;
}