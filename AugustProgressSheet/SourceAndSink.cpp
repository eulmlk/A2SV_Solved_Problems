#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    int adjacency[n][n];
    int sources[n], sinks[n], src = 0, snk = 0;

    bool isSource[n];
    for (int i = 0; i < n; ++i)
        isSource[i] = true;

    for (int i = 0; i < n; ++i) {
        bool isSink = true;

        for (int j = 0; j < n; ++j) {
            cin >> adjacency[i][j];

            if (adjacency[i][j] != 0) {
                isSink = false;
                isSource[j] = false;
            }
        }

        if (isSink) {
            sinks[snk++] = i + 1;
        }
    }

    for (int i = 0; i < n; ++i)
        if (isSource[i])
            sources[src++] = i + 1;

    cout << src << " ";
    for (int i = 0; i < src; ++i)
        cout << sources[i] << " ";
    cout << '\n'
         << snk << " ";
    for (int i = 0; i < snk; ++i)
        cout << sinks[i] << " ";
    cout << '\n';

    return 0;
}