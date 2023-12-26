class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> counts(1001, 0);

        for (int val : arr1) 
            ++counts[val];

        vector<int> result;
        for (int val : arr2) {
            while (counts[val]) {
                result.push_back(val);
                --counts[val];
            }
        }

        for (int i = 0; i <= 1000; ++i) {
            while (counts[i]--) 
                result.push_back(i);
        }

        return result;
    }
};