class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> table;
public:
    TimeMap() {
        
    }

    void set(string_view key, string_view value, int timestamp) {
        table[key.data()].emplace_back(timestamp, value.data());
    }

    string get(string_view key, int timestamp) {
        if (auto it = table.find(key.data()); it != table.end())
        {
            auto func = [](const int val1, const pair<int, string> val2) { return val1 < val2.first; };
            auto answer = upper_bound(it->second.begin(), it->second.end(), timestamp, func);
            if (answer == it->second.begin())
                return "";
            else
                answer--;
            return answer->second;
        }
        else
            return "";
    }
};