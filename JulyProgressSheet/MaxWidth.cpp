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

#define U64 unsigned long long

class Solution {
public:
    int widthOfBinaryTree(TreeNode *root) {
        if (root == nullptr)
            return 0;

        int curMax = INT32_MIN;
        queue<pair<TreeNode *, U64>> queue;

        queue.push({root, 0});

        while (!queue.empty()) {
            int width = queue.back().second - queue.front().second + 1;
            curMax = max(curMax, width);

            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                const auto &cur = queue.front();
                queue.pop();

                TreeNode *node = cur.first;
                U64 pos = cur.second;

                if (node->left != nullptr)
                    queue.push({node->left, 2 * pos});

                if (node->right != nullptr)
                    queue.push({node->right, 2 * pos + 1});
            }
        }

        return curMax;
    }
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

    TreeNode *node3l_3 = new TreeNode(3);
    TreeNode *node4l_3 = new TreeNode(4);
    TreeNode *node4r_3 = new TreeNode(4);
    TreeNode *node3r_3 = new TreeNode(3);

    TreeNode *node2l_3 = new TreeNode(2, node3l_3, node4l_3);
    TreeNode *node2r_3 = new TreeNode(2, node4r_3, node3r_3);

    TreeNode *node1_3 = new TreeNode(1, node2l_3, node2r_3);

    printTree(node1_3);

    cout << solution.widthOfBinaryTree(node1_1) << endl;
    cout << solution.widthOfBinaryTree(node2_2) << endl;
    cout << solution.widthOfBinaryTree(node1_3) << endl;

    freeTree(node1_1);
    freeTree(node2_2);
    freeTree(node1_3);
}
