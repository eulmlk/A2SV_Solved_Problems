#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        stack<int> stk;
        stk.push(0);
        visited[0] = true;
        int count = 0;

        while (!stk.empty()) {
            int u = stk.top();
            stk.pop();
            ++count;

            for (int v : rooms[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    stk.push(v);
                }
            }
        }

        return count == n;
    }
};