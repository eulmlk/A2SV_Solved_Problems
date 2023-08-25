#include <bits/stdc++.h>

using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee *> employees, int id) {
        unordered_map<int, Employee *> mp;
        for (auto &e : employees)
            mp[e->id] = e;

        int importance = 0;
        list<Employee *> stack;
        stack.push_back(mp[id]);
        while (!stack.empty()) {
            Employee *e = stack.back();
            stack.pop_back();

            importance += e->importance;
            for (auto &sub : e->subordinates) {
                stack.push_back(mp[sub]);
            }
        }

        return importance;
    }
};