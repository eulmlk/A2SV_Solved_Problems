class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        int steps = 0, count = 0;
        
        for (int i = 1; i < n; ++i) {
            ++count;

            if (nums[i] != nums[i - 1])
                steps += count;
        }

        return steps;
    }
};