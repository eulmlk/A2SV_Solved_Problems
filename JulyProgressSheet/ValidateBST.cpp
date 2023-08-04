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
    bool isValidBST(TreeNode *root) {
        if (root == nullptr)
            return true;

        list.clear();

        populateList(root);

        int prev = list[0];
        for (int i = 1, n = list.size(); i < n; ++i) {
            if (prev >= list[i])
                return false;

            prev = list[i];
        }

        return true;
    }

private:
    void populateList(TreeNode *node) {
        if (node == nullptr)
            return;

        populateList(node->left);
        list.push_back(node->val);
        populateList(node->right);
    }

private:
    vector<int> list;
};