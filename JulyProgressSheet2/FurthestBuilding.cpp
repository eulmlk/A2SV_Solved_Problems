#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
        priority_queue<int> heap;

        int i = 0, n = heights.size() - 1;
        for (; i < n; i++) {
            int diff = heights[i + 1] - heights[i];

            if (diff <= 0)
                continue;

            bricks -= diff;
            heap.push(diff);

            if (bricks < 0) {
                bricks += heap.top();
                heap.pop();
                ladders--;
            }

            if (ladders < 0)
                break;
        }

        return i;
    }
};