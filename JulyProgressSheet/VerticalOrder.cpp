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
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        traversals.clear();
        auto compare = [](const cell &c1, const cell &c2) {
            if (c1.col == c2.col) {
                if (c1.row == c2.row)
                    return c1.node->val < c2.node->val;

                return c1.row < c2.row;
            }

            return c1.col < c2.col;
        };

        traverse(root, 0, 0);

        sort(traversals.begin(), traversals.end(), compare);

        vector<vector<int>> verticalTraversals;
        int prev = INT32_MIN, cols = -1;
        for (int i = 0, n = traversals.size(); i < n; ++i) {
            const cell &cur = traversals[i];

            if (cur.col != prev) {
                verticalTraversals.push_back(vector<int>{});
                prev = cur.col;
                ++cols;
            }

            verticalTraversals[cols].push_back(cur.node->val);
        }

        return verticalTraversals;
    }

private:
    void traverse(TreeNode *node, int row, int col) {
        if (node == nullptr)
            return;

        traversals.push_back({row, col, node});

        traverse(node->left, row + 1, col - 1);
        traverse(node->right, row + 1, col + 1);
    }

private:
    struct cell {
        int row, col;
        TreeNode *node;
    };

private:
    vector<cell> traversals;
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

void printVector(vector<int> &v) {
    cout << "[ ";
    for (auto val : v) {
        cout << val << " ";
    }
    cout << "]\n";
}

void printVector(vector<vector<int>> &&v) {
    cout << "[\n";
    for (auto val : v) {
        cout << "    ";
        printVector(val);
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

    printVector(solution.verticalTraversal(node1_1));
    printVector(solution.verticalTraversal(node2_2));
    printVector(solution.verticalTraversal(node1_3));

    freeTree(node1_1);
    freeTree(node2_2);
    freeTree(node1_3);
}