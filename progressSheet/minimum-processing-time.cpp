class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.rbegin(), tasks.rend());

        int minTime = INT32_MIN;
        int ind = 0;
        
        for (int processor : processorTime) {
            int time = processor + *max_element(tasks.begin() + ind, tasks.begin() + ind + 4);
            ind += 4;
            minTime = max(minTime, time);
        }

        return minTime;
    }
};