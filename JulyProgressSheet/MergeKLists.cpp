#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        head = nullptr;

        if (lists.empty())
            return head;

        lists.erase(remove(lists.begin(), lists.end(), nullptr), lists.end());
        auto first = lists.begin(), last = lists.end();

        if (lists.size() == 1)
            return lists.front();

        auto compare = [](const ListNode *n1, const ListNode *n2) {
            return n1->val > n2->val;
        };

        while (first != last) {
            make_heap(first, last, compare);

            ListNode *node = removeNode(*first);

            if (*first == nullptr)
                ++first;

            addNode(node);
        }

        return head;
    }

private:
    void addNode(ListNode *node) {
        if (head == nullptr)
            head = tail = node;
        else
            tail->next = node, tail = node;
    }

    ListNode *removeNode(ListNode *&head) {
        if (head == nullptr)
            return nullptr;

        ListNode *temp = head;

        head = head->next;

        return temp;
    }

private:
    ListNode *head;
    ListNode *tail;
};