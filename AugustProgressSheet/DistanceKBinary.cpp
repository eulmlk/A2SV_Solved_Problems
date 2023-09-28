#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        parent.clear();
        populateParents(root, nullptr);

        queue<TreeNode *> q;
        unordered_set<int> visited;
        q.push(target);
        visited.insert(target->val);

        while (k-- && !q.empty()) {
            int qn = q.size();

            while (qn--) {
                TreeNode *cur = q.front();
                q.pop();

                if (cur->left && !visited.count(cur->left->val))
                    q.push(cur->left), visited.insert(cur->left->val);

                if (cur->right && !visited.count(cur->right->val))
                    q.push(cur->right), visited.insert(cur->right->val);

                TreeNode *par = parent[cur];
                if (par && !visited.count(par->val))
                    q.push(par), visited.insert(par->val);
            }
        }

        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }

        return res;
    }

private:
    void populateParents(TreeNode *node, TreeNode *par) {
        if (!node)
            return;

        parent[node] = par;

        populateParents(node->left, node);
        populateParents(node->right, node);
    }

private:
    unordered_map<TreeNode *, TreeNode *> parent;
};