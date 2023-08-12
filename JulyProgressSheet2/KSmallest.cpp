#include <bits/stdc++.h>

using namespace std;

#define cell(r, c, n) (n) * (r) + (c)

class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        priority_queue<Node> heap;
        unordered_set<int> visited;
        int n = matrix.size();

        visited.insert(0);
        heap.push(Node(0, 0, matrix[0][0]));

        while (--k) {
            auto [r, c, val] = heap.top();
            heap.pop();

            if (r + 1 < n && visited.find(cell(r + 1, c, n)) == visited.end()) {
                heap.push(Node(r + 1, c, matrix[r + 1][c]));
                visited.insert(cell(r + 1, c, n));
            }

            if (c + 1 < n && visited.find(cell(r, c + 1, n)) == visited.end()) {
                heap.push(Node(r, c + 1, matrix[r][c + 1]));
                visited.insert(cell(r, c + 1, n));
            }
        }

        return heap.top().val;
    }

private:
    struct Node {
        int r, c;
        int val;

        Node(int r, int c, int val) : r(r), c(c), val(val) {}

        bool operator<(const Node &other) const {
            return val > other.val;
        }
    };
};