class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> counts1, counts2;

        for (int num : nums1)
            ++counts1[num];
        
        for (int num : nums2)
            ++counts2[num];
        
        vector<int> result;

        for (auto [num, count] : counts1) {
            if (counts2.count(num)) {
                count = min(count, counts2[num]);

                while (count--)
                    result.push_back(num);
            }
        }

        return result;
    }
};