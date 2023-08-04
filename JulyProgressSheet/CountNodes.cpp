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
    int averageOfSubtree(TreeNode *root) {
        total = 0;

        countNodes(root);

        return total;
    }

private:
    void sumOfSubTree(TreeNode *root) {
        if (root == nullptr)
            return;

        sum += root->val;
        ++count;
        sumOfSubTree(root->left);
        sumOfSubTree(root->right);
    }

    void countNodes(TreeNode *root) {
        if (root == nullptr)
            return;

        sum = 0;
        count = 0;
        sumOfSubTree(root);
        total += root->val == sum / count;

        countNodes(root->left);
        countNodes(root->right);
    }

private:
    int sum, count, total;
};