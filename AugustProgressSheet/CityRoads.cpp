#include <iostream>

using namespace std;

int main() {
    int n, x;

    cin >> n;

    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> x;
            count += x;
        }
    }

    cout << count / 2 << endl;

    return 0;
}