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
    int maxPathSum(TreeNode *root) {
        maxPath = INT32_MIN;
        dfs(root);
        return maxPath;
    }

private:
    int dfs(TreeNode *node) {
        if (!node)
            return 0;

        int left = max(0, dfs(node->left));
        int right = max(0, dfs(node->right));
        int curVal = left + right + node->val;
        maxPath = max(curVal, maxPath);

        return node->val + max(left, right);
    }

private:
    int maxPath;
};