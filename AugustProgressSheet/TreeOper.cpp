#include <bits/stdc++.h>

using namespace std;

class LockingTree {
public:
    LockingTree(vector<int> &parent) {
        nodes = move(parent);
    }

    bool lock(int num, int user) {
        if (isLocked.find(num) != isLocked.end())
            return false;

        isLocked[num] = user;
        int i = nodes[num];
        while (i != -1) {
            locked[i].insert(num);
            i = nodes[i];
        }

        return true;
    }

    bool unlock(int num, int user) {
        if (isLocked.find(num) == isLocked.end() || isLocked[num] != user)
            return false;

        isLocked.erase(num);
        int i = num;
        while (i != -1) {
            i = nodes[i];
            locked[i].erase(num);
        }

        return true;
    }

    void unlocked(int num) {
        isLocked.erase(num);
        int i = num;
        while (i != -1) {
            i = nodes[i];
            locked[i].erase(num);
        }
    }

    bool upgrade(int num, int user) {
        if (isLocked.find(num) != isLocked.end())
            return false;

        int i = nodes[num];
        while (i != -1) {
            if (isLocked.find(i) != isLocked.end())
                return false;
            i = nodes[i];
        }

        if (locked[num].size() == 0)
            return false;

        for (auto it : locked[num])
            unlocked(it);

        return lock(num, user);
    }

private:
    unordered_map<int, int> isLocked;
    unordered_map<int, set<int>> locked;
    vector<int> nodes;
};