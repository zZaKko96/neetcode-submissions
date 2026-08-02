class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded;
        for (const string& s : strs) {
            encoded += to_string(s.size()) + '#' + s;
        }
        return encoded;
    }

    vector<string> decode(string_view s) {
        vector<string> decoded;
        size_t i = 0;

        while (i < s.size()) {
            size_t j = s.find('#', i);
            int length = stoi(string(s.substr(i, j - i)));
            i = j + 1;

            decoded.emplace_back(s.substr(i, length));

            i += length;
        }

        return decoded;
    }
};