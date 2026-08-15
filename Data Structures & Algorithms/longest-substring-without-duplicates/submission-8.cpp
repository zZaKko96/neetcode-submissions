class Solution {
public:
    int lengthOfLongestSubstring(string_view s) {
        int last_index[128] = { 0 };
        int max_len = 0;
        int left = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            unsigned char c = s[right];

            left = max(left, last_index[c]);

            max_len = max(max_len, right - left + 1);
            last_index[c] = right + 1;
        }

        return max_len;
    }
};