#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int racecar(int target) {
        queue<pair<long long, long long>> q;
        set<pair<long long, long long>> visited;

        int steps = 0;
        q.emplace(0, 1);
        visited.emplace(0, 1);
        while (!q.empty()) {
            long long qn = q.size();

            while (qn--) {
                auto [cur, speed] = q.front();
                q.pop();

                if (cur == target)
                    return steps;

                long long next1 = cur + speed, spd1 = speed * 2;
                if (!visited.count({next1, spd1}))
                    q.emplace(next1, spd1), visited.emplace(next1, spd1);

                if ((cur + speed) > target && speed > 0 || (cur + speed) < target && speed < 0) {
                    long long next2 = cur, spd2 = speed > 0 ? -1 : 1;
                    if (!visited.count({next2, spd2}))
                        q.emplace(next2, spd2), visited.emplace(next2, spd2);
                }
            }

            ++steps;
        }

        return -1;
    }
};