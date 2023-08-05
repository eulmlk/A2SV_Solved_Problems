#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words) {
        int left = 0, right = words.size();
        vector<int> answer;
        vector<int> f_words;
        f_words.reserve(right);
        answer.reserve(queries.size());

        for (int i = 0; i < right; ++i) {
            f_words.push_back(f(words[i]));
        }

        sort(f_words.begin(), f_words.end());

        for (string query : queries) {
            int sf = getSmallerByFrequency(f_words, query, left, right - 1);
            answer.push_back(right - sf);
        }

        return answer;
    }

private:
    int getSmallerByFrequency(vector<int> &f_words, string query, int left, int right) {
        int q = f(query);

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (q < f_words[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }

    int f(string s) {
        char ch = *min_element(s.begin(), s.end());
        return count(s.begin(), s.end(), ch);
    }
};

void printVector(vector<int> &&v) {
    cout << "[ ";
    for (auto val : v) {
        cout << val << " ";
    }
    cout << "]\n";
}

int main() {
    Solution solution;

    vector<string> q1 = {"cbd"};
    vector<string> q2 = {"bbb", "cc"};

    vector<string> w1 = {"zaaaz"};
    vector<string> w2 = {"a", "aa", "aaa", "aaaa"};

    printVector(solution.numSmallerByFrequency(q1, w1));
    printVector(solution.numSmallerByFrequency(q2, w2));
}