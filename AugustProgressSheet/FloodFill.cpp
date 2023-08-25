#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        q.emplace(sr, sc);
        while (!q.empty()) {
            auto [cr, cc] = q.front();
            q.pop();
            int cur = image[cr][cc];
            image[cr][cc] = color;

            if (cr + 1 < n && image[cr + 1][cc] == cur && !visited[cr + 1][cc]) {
                q.emplace(cr + 1, cc);
                visited[cr + 1][cc] = 1;
            }
            if (cr - 1 >= 0 && image[cr - 1][cc] == cur && !visited[cr - 1][cc]) {
                q.emplace(cr - 1, cc);
                visited[cr - 1][cc] = 1;
            }
            if (cc + 1 < m && image[cr][cc + 1] == cur && !visited[cr][cc + 1]) {
                q.emplace(cr, cc + 1);
                visited[cr][cc + 1] = 1;
            }
            if (cc - 1 >= 0 && image[cr][cc - 1] == cur && !visited[cr][cc - 1]) {
                q.emplace(cr, cc - 1);
                visited[cr][cc - 1] = 1;
            }
        }

        return image;
    }
};