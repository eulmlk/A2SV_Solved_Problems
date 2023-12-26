class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int count = 0;
        int lowest = INT32_MAX, highest = INT32_MIN;

        for (int index = 0; index < flips.size(); ++index) {
            lowest = min(flips[index], lowest);
            highest = max(flips[index], highest);

            if (lowest == 1 && highest == index + 1)
                ++count;
        }

        return count;
    }
};