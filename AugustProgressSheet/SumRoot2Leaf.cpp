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
    int sumNumbers(TreeNode *root) {
        return sumNumbers(root, 0);
    }

private:
    int sumNumbers(TreeNode *root, int sum) {
        sum *= 10;
        sum += root->val;

        if (!root->left && !root->right)
            return sum;

        if (!root->left)
            return sumNumbers(root->right, sum);

        if (!root->right)
            return sumNumbers(root->left, sum);

        return sumNumbers(root->left, sum) + sumNumbers(root->right, sum);
    }
};