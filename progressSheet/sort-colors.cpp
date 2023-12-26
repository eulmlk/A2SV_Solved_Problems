class Solution {
public:
    void sortColors(vector<int>& nums) {
        int counts[3] = {0, 0, 0};

        for (int val : nums)
            ++counts[val];

        nums.clear();
        while (counts[0]--)
            nums.push_back(0);

        while (counts[1]--)
            nums.push_back(1);

        while (counts[2]--)
            nums.push_back(2);
    }
};