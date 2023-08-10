class Solution {
public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> freq;
        vector<string> result;

        for (const auto &word : words) {
            ++freq[word];
        }

        auto compare = [&](const string &s1, const string &s2) {
            if (freq[s1] == freq[s2])
                return s1 < s2;

            return freq[s1] > freq[s2];
        };

        priority_queue<string, vector<string>, decltype(compare)> heap(compare);

        for (const auto &pair : freq) {
            heap.push(pair.first);

            if (heap.size() > k) {
                heap.pop();
            }
        }

        while (!heap.empty()) {
            result.push_back(heap.top());
            heap.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};