class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int left = 0, right = skill.size() - 1;
        long long product = 0;

        while (left < right) {
            if (skill[left + 1] - skill[left] != skill[right] - skill[right - 1])
                return -1;

            product += (long long)(skill[left]) * skill[right];

            ++left;
            --right;
        }

        return product;
    }
};