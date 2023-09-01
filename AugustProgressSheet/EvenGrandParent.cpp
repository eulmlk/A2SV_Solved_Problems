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
    int sumEvenGrandparent(TreeNode *root) {
        sum = 0;
        dfs(root);
        return sum;
    }

private:
    void dfs(TreeNode *node) {
        if (!node)
            return;

        if (node->val % 2 == 0) {
            if (node->left) {
                if (node->left->left)
                    sum += node->left->left->val;
                if (node->left->right)
                    sum += node->left->right->val;
            }
            if (node->right) {
                if (node->right->left)
                    sum += node->right->left->val;
                if (node->right->right)
                    sum += node->right->right->val;
            }
        }

        dfs(node->left);
        dfs(node->right);
    }

private:
    int sum = 0;
};