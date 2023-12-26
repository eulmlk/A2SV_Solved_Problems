class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> people;

        for (int i = 0; i < names.size(); ++i) 
            people.emplace_back(heights[i], names[i]);
        
        int n = people.size();
        for (int i = 1; i < n; ++i) {
            int j = i - 1;
            pair<int, string> temp = move(people[i]);
            
            while (j >= 0 && people[j].first < temp.first) {
                people[j + 1] = move(people[j]);
                --j;
            }

            people[j + 1] = move(temp);
        }

        vector<string> result;

        for (const auto &[height, name] : people)
            result.push_back(name);

        return result;
    }
};