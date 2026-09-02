class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> table;

public:
    TimeMap() = default;

    void set(string key, string value, int timestamp) {
        table[std::move(key)].emplace_back(timestamp, std::move(value));
    }

    string get(const string& key, int timestamp) {
        auto it = table.find(key);
        if (it == table.end()) {
            return "";
        }

        const auto& history = it->second;
        auto func = [](int val1, const pair<int, string>& val2) {
            return val1 < val2.first;
            };

        auto answer = upper_bound(history.begin(), history.end(), timestamp, func);
        if (answer == history.begin()) {
            return "";
        }

        return prev(answer)->second;
    }
};