#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target) {
        if (source == target)
            return 0;

        unordered_map<int, vector<int>> toRoutes;
        for (int i = 0; i < routes.size(); ++i) {
            for (int stop : routes[i])
                toRoutes[stop].push_back(i);
        }

        queue<int> q;
        q.push(source);

        unordered_set<int> visitedStops;
        unordered_set<int> visitedRoutes;
        int buses = 0;

        while (!q.empty()) {
            int k = q.size();

            while (k--) {
                int stop = q.front();
                q.pop();

                if (stop == target)
                    return buses;

                for (int route : toRoutes[stop]) {
                    if (visitedRoutes.find(route) == visitedRoutes.end()) {
                        visitedRoutes.insert(route);
                        for (int next : routes[route]) {
                            if (visitedStops.find(next) == visitedStops.end()) {
                                visitedStops.insert(next);
                                q.push(next);
                            }
                        }
                    }
                }
            }

            ++buses;
        }

        return -1;
    }
};
