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
    vector<int> findMode(TreeNode *root) {
        map.clear();
        curMax = INT32_MIN;

        traverse(root);

        vector<int> modes;
        for (const auto &pair : map) {
            if (pair.second == curMax) {
                modes.push_back(pair.first);
            }
        }

        return modes;
    }

private:
    void traverse(TreeNode *node) {
        if (node == nullptr)
            return;

        traverse(node->left);
        ++map[node->val];
        curMax = max(curMax, map[node->val]);
        traverse(node->right);
    }

private:
    unordered_map<int, int> map;
    int curMax;
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

void printVector(vector<int> &&v) {
    cout << "[ ";
    for (auto val : v) {
        cout << val << " ";
    }
    cout << "]\n";
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

    TreeNode *node3l_3 = new TreeNode(3);
    TreeNode *node4l_3 = new TreeNode(4);
    TreeNode *node4r_3 = new TreeNode(4);
    TreeNode *node3r_3 = new TreeNode(3);

    TreeNode *node2l_3 = new TreeNode(2, node3l_3, node4l_3);
    TreeNode *node2r_3 = new TreeNode(2, node4r_3, node3r_3);

    TreeNode *node1_3 = new TreeNode(1, node2l_3, node2r_3);

    printTree(node1_3);

    printVector(solution.findMode(node1_1));
    printVector(solution.findMode(node2_2));
    printVector(solution.findMode(node1_3));

    freeTree(node1_1);
    freeTree(node2_2);
    freeTree(node1_3);
}