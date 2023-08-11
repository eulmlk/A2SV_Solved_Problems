class Solution {
public:
    bool isPossible(vector<int> &nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> tails;

        for (int num : nums)
            freq[num]++;

        for (int num : nums) {
            if (freq[num] == 0)
                continue;

            if (tails[num - 1] > 0) {
                --tails[num - 1];
                ++tails[num];
            } else if (freq[num + 1] > 0 && freq[num + 2] > 0) {
                --freq[num + 1];
                --freq[num + 2];
                ++tails[num + 2];
            } else {
                return false;
            }
            --freq[num];
        }

        return true;
    }
};
