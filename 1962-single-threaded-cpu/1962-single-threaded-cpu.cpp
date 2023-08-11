class Solution {
public:
    vector<int> getOrder(vector<vector<int>> &tasks) {
        int n = tasks.size();
        vector<int> result;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

        for (int i = 0; i < n; ++i)
            tasks[i].push_back(i);

        sort(tasks.begin(), tasks.end());

        long long curTime = 0;
        int index = 0;

        for (int i = 0; i < n; ++i) {
            while (index < n && tasks[index][0] <= curTime) {
                heap.push({tasks[index][1], tasks[index][2]});
                index++;
            }

            if (!heap.empty()) {
                auto [cost, index] = heap.top();
                heap.pop();
                result.push_back(index);
                curTime += (long long)cost;
            } else {
                curTime = tasks[index][0];
                i--;
            }
        }

        return result;
    }
};