class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> myMap;

        for (const string& s : strs) {
            string key(26, 0);
            for (char c : s) {
                key[c - 'a']++;
            }
            myMap[key].push_back(s);
        }

        vector<vector<string>> myVec;
        myVec.reserve(myMap.size());

        for (auto& [key, group] : myMap) {
            myVec.push_back(std::move(group));
        }

        return myVec;
    }
};