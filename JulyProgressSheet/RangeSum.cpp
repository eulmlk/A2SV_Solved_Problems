#include <bits/stdc++.h>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        size = nums.size();
        numbs = new int[size];

        memcpy(numbs, &(*nums.begin()), size * sizeof(int));
    }

    ~NumArray() {
        delete[] numbs;
    }

    int sumRange(int left, int right) {
        int sum = 0;

        for (int i = left; i <= right; ++i) {
            sum += numbs[i];
        }

        return sum;
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