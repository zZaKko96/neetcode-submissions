class Solution {
public:
    int lengthOfLongestSubstring(string_view s) {
        if (s.empty()) return 0;

        int n = s.size();

        int lenght = 1;
        bitset<128> bits;

        for (int i = 0, j = 0; j < n;)
        {
            if (bits.test(s[j]))
            {
                while (true)
                {
                    bits.reset(s[i]);
                    i++;
                    if (s[i - 1] == s[j]) break;
                }
            }
            else
            {
                bits.set(s[j]);
                lenght = max(lenght, j - i + 1);
                j++;
            }
        }

        return lenght;
    }
};