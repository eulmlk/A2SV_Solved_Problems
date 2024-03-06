class TimeMap {
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        data[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> &arr = data[key];

        // for (auto &[tm, str] : arr) {
        //     cout << "(" << tm << ", " << str << ")  ";
        // }
        // cout << endl;
        // cout << "tar: " << key << " - " << timestamp << endl;

        int left = 0, right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid].first > timestamp)
                right = mid - 1;
            else
                left = mid + 1;
        }

        if (right > -1)
            return arr[right].second;
        else
            return "";
    }

private:
    unordered_map<string, vector<pair<int, string>>> data;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */