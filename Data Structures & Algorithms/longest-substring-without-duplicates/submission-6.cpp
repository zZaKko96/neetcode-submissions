class Solution {
public:
    int lengthOfLongestSubstring(string_view s) {
        if (s.empty()) return 0;

        int max_len = 0;
        bitset<128> bits;

        for (size_t left = 0, right = 0; right < s.size(); ++right) {
            while (bits.test(s[right])) {
                bits.reset(s[left]);
                left++;
            }

            bits.set(s[right]);
            max_len = max(max_len, static_cast<int>(right - left + 1));
        }

        return max_len;
    }
};