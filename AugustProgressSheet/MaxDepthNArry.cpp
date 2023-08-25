#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node *root) {
        if (!root)
            return 0;

        list<pair<Node *, int>> stack;
        int maxVal = INT32_MIN;

        stack.emplace_back(root, 1);
        while (!stack.empty()) {
            auto [cur, depth] = stack.back();
            stack.pop_back();

            maxVal = max(maxVal, depth);
            for (Node *node : cur->children) {
                stack.emplace_back(node, depth + 1);
            }
        }

        return maxVal;
    }
};