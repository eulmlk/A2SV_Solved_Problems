class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        unordered_map<int, int> freqMap;

        for (int num : nums)
            ++freqMap[num];
        
        vector<pair<int, int>> counts;
        for (auto [num, freq] : freqMap)
            counts.emplace_back(num, freq);
        
        sort(counts.rbegin(), counts.rend());

        int steps = 0;
        for (int i = 0; i < counts.size() - 1; ++i) {
            int freq = counts[i].second;
            steps += freq;
            counts[i + 1].second += freq;
        }

        return steps;
    }
};