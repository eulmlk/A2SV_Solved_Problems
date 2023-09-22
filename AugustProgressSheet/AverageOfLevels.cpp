#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> result;
        queue<pair<TreeNode *, int>> q;
        q.emplace(root, 0);

        int cur = 0;
        double sum = 0.0;
        int count = 0;
        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop();

            if (cur < level) {
                result.push_back(sum / count);
                sum = count = 0;
                ++cur;
            }

            sum += node->val;
            ++count;

            if (node->left)
                q.emplace(node->left, level + 1);

            if (node->right)
                q.emplace(node->right, level + 1);
        }
        result.push_back(sum / count);

        return result;
    }
};