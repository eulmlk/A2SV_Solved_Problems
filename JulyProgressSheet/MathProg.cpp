#include <bits/stdc++.h>

using namespace std;

int main() {
    int testCases;

    cin >> testCases;

    while (testCases--) {
        int a, b;

        cin >> a >> b;

        cout << min(min(a, b), (a + b) / 4) << endl;
    }

    return 0;
}