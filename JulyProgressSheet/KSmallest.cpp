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
    int kthSmallest(TreeNode *root, int k) {
        cur = 0;
        this->k = k;
        return traverse(root);
    }

private:
    int traverse(TreeNode *root) {
        if (root == nullptr)
            return -1;

        int left = traverse(root->left);
        if (left != -1)
            return left;

        if (++cur == k)
            return root->val;

        return traverse(root->right);
    }

private:
    int cur, k;
};
