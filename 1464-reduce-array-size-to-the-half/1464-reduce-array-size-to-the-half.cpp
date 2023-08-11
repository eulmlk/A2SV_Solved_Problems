class Solution {
public:
    int minSetSize(vector<int> &arr) {
        unordered_map<int, int> freq;
        priority_queue<int> heap;

        for (int num : arr)
            freq[num]++;

        for (auto pair : freq)
            heap.push(pair.second);

        int setSize = 0;
        int removed = 0;
        int half = arr.size() / 2;

        while (!heap.empty() && removed < half) {
            removed += heap.top();
            heap.pop();
            setSize++;
        }

        return setSize;
    }
};