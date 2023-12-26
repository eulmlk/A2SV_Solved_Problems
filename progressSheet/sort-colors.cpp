class Solution {
public:
    void sortColors(vector<int>& nums) {
        int counts[3] = {0, 0, 0};

        for (int val : nums)
            ++counts[val];

        int ind = 0;
        while (counts[0]--)
            nums[ind++] = 0;

        while (counts[1]--)
            nums[ind++] = 1;

        while (counts[2]--)
            nums[ind++] = 2;
    }
};