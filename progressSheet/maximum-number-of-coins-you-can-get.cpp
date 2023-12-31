class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());

        int left = 0, right = piles.size() - 1;
        int myCoins = 0;

        while (left < right) {
            ++left;
            --right;
            myCoins += piles[right--];
        }

        return myCoins;
    }
};