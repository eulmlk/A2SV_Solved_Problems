class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto distance = [](const vector<int> &point) {
            return point[0] * point[0] + point[1] * point[1];
        };

        auto compare = [&](const vector<int> &point1, const vector<int> &point2) {
            return distance(point1) < distance(point2);
        };

        sort(points.begin(), points.end(), compare);
        points.resize(k);
        return points;
    }
};