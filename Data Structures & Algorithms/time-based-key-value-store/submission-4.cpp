class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> table;
public:
    TimeMap() {
        
    }

    void set(string_view key, string_view value, int timestamp) {
        table[string(key)].emplace_back(timestamp, string(value));
    }

    string get(string_view key, int timestamp) {
        if (auto it = table.find(string(key)); it != table.end())
        {
            auto func = [](const int val1, const pair<int, string>& val2) { return val1 < val2.first; };
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