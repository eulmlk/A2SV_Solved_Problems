#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>> &edges) {
        int v11 = edges[0][0], v12 = edges[0][1];
        int v21 = edges[1][0], v22 = edges[1][1];

        if (v11 == v21 || v11 == v22)
            return v11;

        if (v12 == v21 || v12 == v22)
            return v12;

        return -1;
    }
};

int main() {
}