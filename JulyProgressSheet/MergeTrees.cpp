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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr && root2 == nullptr)
            return nullptr;

        if (root1 == nullptr)
            root1 = &node;

        if (root2 == nullptr)
            root2 = &node;

        TreeNode *left = mergeTrees(root1->left, root2->left);
        TreeNode *right = mergeTrees(root1->right, root2->right);
        int val = root1->val + root2->val;

        return new TreeNode(val, left, right);
    }

private:
    TreeNode node;
};

void freeTree(TreeNode *root) {
    if (root == nullptr)
        return;

    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void printTree(TreeNode *root, int offset = 0) {
    if (root == nullptr)
        return;

    for (int i = 0; i < offset; ++i)
        cout << "  ";

    cout << "+-> " << root->val << endl;
    printTree(root->left, offset + 1);
    printTree(root->right, offset + 1);
}

int main() {
    Solution solution;

    TreeNode *node5_1 = new TreeNode(5);

    TreeNode *node2_1 = new TreeNode(2);
    TreeNode *node3_1 = new TreeNode(3, node5_1, nullptr);

    TreeNode *node1_1 = new TreeNode(1, node3_1, node2_1);

    printTree(node1_1);

    TreeNode *node4_2 = new TreeNode(4);
    TreeNode *node7_2 = new TreeNode(7);

    TreeNode *node1_2 = new TreeNode(1, nullptr, node4_2);
    TreeNode *node3_2 = new TreeNode(3, nullptr, node7_2);

    TreeNode *node2_2 = new TreeNode(2, node1_2, node3_2);

    printTree(node2_2);

    TreeNode *merged = solution.mergeTrees(node1_1, node2_2);
    printTree(merged);

    freeTree(node1_1);
    freeTree(node2_2);
    freeTree(merged);
}