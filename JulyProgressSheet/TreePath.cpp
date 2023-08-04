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
    vector<string> binaryTreePaths(TreeNode *root) {
        paths.clear();

        populatePaths(root, "");

        return paths;
    }

private:
    void populatePaths(TreeNode *node, string path) {
        path += to_string(node->val);
        bool hasChild = false;
        if (node->left != nullptr)
            populatePaths(node->left, path + "->"), hasChild = true;

        if (node->right != nullptr)
            populatePaths(node->right, path + "->"), hasChild = true;

        if (!hasChild)
            paths.push_back(path);
    }

private:
    vector<string> paths;
};

void printVector(vector<string> &&v) {
    cout << "[ ";
    for (auto val : v) {
        cout << val << " ";
    }
    cout << "]\n";
}

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

    TreeNode *node5 = new TreeNode(5);

    TreeNode *node2 = new TreeNode(2, nullptr, node5);
    TreeNode *node3 = new TreeNode(3);

    TreeNode *node1 = new TreeNode(1, node2, node3);

    printTree(node1);

    printVector(solution.binaryTreePaths(node1));

    freeTree(node1);
}