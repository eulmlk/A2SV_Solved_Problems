class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxVal = *max_element(costs.begin(), costs.end());
        vector<int> counts(maxVal + 1, 0);

        for (int cost : costs)
            ++counts[cost];
        
        int bought = 0;
        for (int num = 1; num <= min(maxVal, coins); ++num) {
            while (counts[num] && num <= coins) {
                coins -= num;
                --counts[num];
                ++bought;
            }
        }

        return bought;
    }
};