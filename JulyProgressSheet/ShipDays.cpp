#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int> &weights, int days) {
        int minCapacity = *max_element(weights.begin(), weights.end());
        int maxCapacity = accumulate(weights.begin(), weights.end(), 0);

        while (minCapacity < maxCapacity) {
            int midCapacity = minCapacity + (maxCapacity - minCapacity) / 2;

            if (isPossible(weights, days, midCapacity)) {
                maxCapacity = midCapacity;
            } else {
                minCapacity = midCapacity + 1;
            }
        }

        return minCapacity;
    }

private:
    bool isPossible(vector<int> &weights, int days, int capacity) {
        int currentDay = 1;
        int currentCapacity = 0;

        for (int weight : weights) {
            if (currentCapacity + weight > capacity) {
                currentDay++;
                currentCapacity = 0;
            }

            currentCapacity += weight;
        }

        return currentDay <= days;
    }
};

int main() {
    Solution solution;

    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v2 = {3, 2, 2, 4, 1, 4};
    vector<int> v3 = {1, 2, 3, 1, 1};

    cout << solution.shipWithinDays(v1, 5) << endl;
    cout << solution.shipWithinDays(v2, 3) << endl;
    cout << solution.shipWithinDays(v3, 4) << endl;

    return 0;
}