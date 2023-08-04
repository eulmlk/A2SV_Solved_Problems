#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int distributeCookies(vector<int> &cookies, int k) {
        minUnfair = INT32_MAX;
        bucket = new int[k];
        memset(bucket, 0, k * sizeof(int));

        searchCookies(cookies, k, 0);

        delete[] bucket;
        return minUnfair;
    }

private:
    void searchCookies(vector<int> &cookies, int k, int index) {
        int n = cookies.size();
        if (index >= n) {
            minUnfair = min(minUnfair, *max_element(bucket, bucket + k));
            return;
        }

        if (*max_element(bucket, bucket + k) > minUnfair)
            return;

        for (int i = 0; i < k; ++i) {
            bucket[i] += cookies[index];
            searchCookies(cookies, k, index + 1);
            bucket[i] -= cookies[index];
        }
    }

private:
    int minUnfair;
    int *bucket;
};

int main() {
    Solution solution;

    vector<int> v1 = {8, 15, 10, 20, 8};
    vector<int> v2 = {6, 1, 3, 2, 2, 4, 1, 2};

    cout << solution.distributeCookies(v1, 2) << endl;
    cout << solution.distributeCookies(v2, 3) << endl;

    return 0;
}