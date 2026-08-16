class Solution {
public:
    int characterReplacement(string_view s, int k) {
        int count[26] = { 0 };
        int max_freq = 0;
        int max_len = 0;
        int left = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            int current_count = ++count[s[right] - 'A'];
            max_freq = max(max_freq, current_count);

            if (int newLen = (right - left + 1); newLen - max_freq > k) {
                count[s[left] - 'A']--;
                left++;
            } 
            else
                max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};