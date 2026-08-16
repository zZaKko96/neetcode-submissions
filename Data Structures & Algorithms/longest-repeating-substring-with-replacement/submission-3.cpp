class Solution {
public:
    int characterReplacement(string_view s, int k) {
        int count[26] = { 0 };
        int max_freq = 0;
        int left = 0;
        int size = static_cast<int>(s.size());

        for (int right = 0; right < size; ++right) {
            max_freq = max(max_freq, ++count[s[right] - 'A']);

            if ((right - left + 1) - max_freq > k) {
                count[s[left] - 'A']--;
                left++;
            }
        }

        return size - left;
    }
};