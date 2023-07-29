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
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode *left = head;
        ListNode *mid = midOf(head);
        ListNode *right = mid->next;
        mid->next = nullptr;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }

private:
    ListNode *midOf(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode *merge(ListNode *list1, ListNode *list2) {
        ListNode *temp = new ListNode(-1);
        ListNode *dummy = temp;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if (list1) {
            temp->next = list1;
        }

        if (list2) {
            temp->next = list2;
        }

        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }
};

void printList(ListNode *head) {
    cout << "[ ";
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "]\n";
}

void freeList(ListNode *head) {
    while (head != nullptr) {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

void makeList(ListNode *&head, ListNode *&tail, vector<int> &&v) {
    for (int i = 0, n = v.size(); i < n; ++i) {
        ListNode *temp = new ListNode(v[i]);

        if (head == nullptr) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
}

int main() {
    Solution solution;

    ListNode *head;
    ListNode *tail;

    // makeList(head, tail, vector<int>({4, 2, 1, 3}));
    makeList(head, tail, vector<int>({-1, 0, 3, 4, 5}));

    head = solution.sortList(head);

    printList(head);

    freeList(head);
}