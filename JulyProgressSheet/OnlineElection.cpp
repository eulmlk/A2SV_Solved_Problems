#include <bits/stdc++.h>

using namespace std;

class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int> &persons, vector<int> &times) {
        size = persons.size();
        int counts[size];
        int leader = -1, leadCount = 0;
        votes = new vote[size];
        memset(counts, 0, size * sizeof(int));

        for (int i = 0; i < size; ++i) {
            int addCount = ++counts[persons[i]];
            leader = addCount >= leadCount ? persons[i] : leader;
            leadCount = addCount >= leadCount ? addCount : leadCount;

            votes[i] = {times[i], leader};
        }
    }

    ~TopVotedCandidate() {
        delete[] votes;
    }

    int q(int t) {
        int left = 0, right = size - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (votes[mid].time > t)
                right = mid - 1;
            else
                left = mid + 1;
        }

        if (left > 0)
            --left;
        return votes[left].leader;
    }

private:
    struct vote {
        int time, leader;
    };

    vote *votes;
    int size;
};

int main() {
    // vector<int> p = {0, 1, 1, 0, 0, 1, 0};
    // vector<int> t = {0, 5, 10, 15, 20, 25, 30};

    vector<int> p = {0, 1, 2, 2, 3, 1, 0, 0, 3, 1, 3, 0, 3, 4, 4, 3, 2, 1, 0, 3};
    vector<int> t = {0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95};

    TopVotedCandidate *obj = new TopVotedCandidate(p, t);

    cout << obj->q(3) << endl;
    cout << obj->q(12) << endl;
    cout << obj->q(25) << endl;
    cout << obj->q(15) << endl;
    cout << obj->q(24) << endl;
    cout << obj->q(8) << endl;

    delete obj;
}