#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        combination.clear();
        sub.clear();

        enumerateCombinations(0, n, k);

        return combination;
    }

private:
    void enumerateCombinations(int index, int n, int k) {
        if (sub.size() == k) {
            combination.push_back(sub);
            return;
        }

        if (index >= n)
            return;

        sub.push_back(index + 1);
        enumerateCombinations(index + 1, n, k);

        sub.pop_back();
        enumerateCombinations(index + 1, n, k);
    }

private:
    vector<vector<int>> combination;
    vector<int> sub;
};

void printVector(vector<int> &v) {
    cout << "[ ";
    for (auto val : v) {
        cout << val << " ";
    }
    cout << "]\n";
}

void printVector(vector<vector<int>> powerSet) {
    cout << "[\n";
    for (auto val : powerSet) {
        cout << "    ";
        printVector(val);
    }
    cout << "]\n";
}

int main() {
    Solution solution;

    printVector(solution.combine(4, 2));
    printVector(solution.combine(1, 1));
}
