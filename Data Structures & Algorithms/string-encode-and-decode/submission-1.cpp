class Solution {
public:
    string encode(vector<string>& strs) {
        size_t totalLen = 0;
        for (const auto& s : strs) {
            totalLen += to_string(s.size()).size() + 1 + s.size();
        }

        string encoded;
        encoded.reserve(totalLen);

        for (const auto& s : strs) {
            encoded += to_string(s.size());
            encoded += '#';
            encoded += s;
        }

        return encoded;
    }

    vector<string> decode(string_view s) {
        vector<string> decoded;
        size_t i = 0;

        while (i < s.size()) {
            size_t j = s.find('#', i);

            int length = 0;
            from_chars(s.data() + i, s.data() + j, length);

            i = j + 1;

            decoded.emplace_back(s.substr(i, length));

            i += length;
        }

        return decoded;
    }
};