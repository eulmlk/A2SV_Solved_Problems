class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<vector<int>> result;
        result.reserve(k);

        int n = nums1.size(), m = nums2.size();
        priority_queue<Pairs> heap;

        for (int i = 0; i < k && i < n; ++i)
            heap.push({Pairs(nums1[i], nums2[0], i, 0)});

        while (!heap.empty() && k--) {
            auto pr = heap.top();
            heap.pop();
            result.push_back({pr.val1, pr.val2});

            if (pr.ind2 + 1 < m)
                heap.push(Pairs(nums1[pr.ind1], nums2[pr.ind2 + 1], pr.ind1, pr.ind2 + 1));
        }

        return result;
    }

private:
    struct Pairs {
        int val1, val2, ind1, ind2;
        int sum;

        Pairs(int v1, int v2, int i1, int i2) : val1(v1), val2(v2), sum(v1 + v2), ind1(i1), ind2(i2) {}

        bool operator<(const Pairs &other) const {
            return sum > other.sum;
        }
    };
};