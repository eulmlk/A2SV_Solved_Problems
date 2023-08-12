#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minStoneSum(vector<int> &piles, int k) {
        priority_queue<int> heap;
        int sum = 0;

        for (int pile : piles)
            heap.push(pile);

        while (k--) {
            int top = heap.top();
            heap.pop();
            top -= top / 2;
            heap.push(top);
        }

        while (!heap.empty()) {
            sum += heap.top();
            heap.pop();
        }

        return sum;
    }
};
