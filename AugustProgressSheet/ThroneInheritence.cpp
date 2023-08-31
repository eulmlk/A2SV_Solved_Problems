#include <bits/stdc++.h>

using namespace std;

class ThroneInheritance {
public:
    ThroneInheritance(string kingName) {
        people[kingName] = list<string>();
        isAlive[kingName] = true;
        king = kingName;
    }

    void birth(string parentName, string childName) {
        people[parentName].push_back(childName);
        people[childName] = list<string>();
        isAlive[childName] = true;
    }

    void death(string name) {
        isAlive[name] = false;
    }

    vector<string> getInheritanceOrder() {
        dfs();
        return inheritanceOrder;
    }

private:
    void dfs() {
        inheritanceOrder.clear();
        stack<string> stk;
        stk.push(king);

        while (!stk.empty()) {
            string person = stk.top();
            stk.pop();

            if (isAlive[person])
                inheritanceOrder.push_back(person);

            const list<string> &children = people[person];
            for (auto ptr = children.rbegin(); ptr != children.rend(); ++ptr)
                stk.push(*ptr);
        }
    }

private:
    vector<string> inheritanceOrder;
    unordered_map<string, list<string>> people;
    unordered_map<string, bool> isAlive;
    string king;
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
