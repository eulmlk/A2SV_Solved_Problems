#include <bits/stdc++.h>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        size = nums.size() + 1;
        numbs = new int[size];
        int sum = 0;
        numbs[0] = 0;

        for (int i = 1; i < size; ++i) {
            sum += nums[i - 1];
            numbs[i] = sum;
            cout << numbs[i] << " ";
        }
        cout << endl;
    }

    ~NumArray() {
        delete[] numbs;
    }

    int sumRange(int left, int right) {
        return numbs[right + 1] - numbs[left];
    }

private:
    int *numbs;
    int size;
};

int main() {
    vector<int> v = {-2, 0, 3, -5, 2, -1};
    NumArray *obj = new NumArray(v);

    cout << obj->sumRange(0, 2) << endl;
    cout << obj->sumRange(2, 5) << endl;
    cout << obj->sumRange(0, 5) << endl;

    delete obj;
}