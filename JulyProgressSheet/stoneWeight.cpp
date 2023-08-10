#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int> &stones) {
        if (stones.size() == 1)
            return stones.front();

        make_heap(stones.begin(), stones.end());

        while (stones.size() > 1) {
            pop_heap(stones.begin(), stones.end());
            int w1 = stones.back();
            stones.pop_back();

            pop_heap(stones.begin(), stones.end());
            int w2 = stones.back();
            stones.pop_back();

            if (w1 != w2)
                stones.push_back(abs(w1 - w2));
        }

        return stones.empty() ? 0 : stones.front();
    }
};
