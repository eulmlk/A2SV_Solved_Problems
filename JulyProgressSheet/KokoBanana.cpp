#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int min = 1;
        int max = *max_element(piles.begin(), piles.end());

        while (min < max) {
            int mid = min + (max - min) / 2;

            if (isPossible(piles, h, mid)) {
                max = mid;
            } else {
                min = mid + 1;
            }
        }

        return min;
    }

private:
    bool isPossible(vector<int> &piles, int h, int speed) {
        int currentHr = 0;
        int eaten = 0;

        for (int pile : piles) {
            currentHr += pile / speed;
            currentHr += pile % speed != 0;
        }

        return currentHr <= h;
    }
};

int main() {
    Solution solution;

    vector<int> v1 = {3, 6, 7, 11};
    vector<int> v2 = {30, 11, 23, 4, 20};
    vector<int> v3 = {312884470};

    cout << solution.minEatingSpeed(v1, 8) << endl;
    cout << solution.minEatingSpeed(v2, 5) << endl;
    cout << solution.minEatingSpeed(v2, 6) << endl;
    cout << solution.minEatingSpeed(v3, 312884469) << endl;

    return 0;
}