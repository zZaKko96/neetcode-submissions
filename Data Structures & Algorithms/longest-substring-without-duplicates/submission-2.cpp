class Solution {
public:
    int lengthOfLongestSubstring(string_view s) {
        if (s.empty()) return 0;
        size_t n = s.size();
        int lenght = 1;
        bitset<128> bits;

        int count;
        for (size_t i = 0, j; i < n-1; i++)
        {
            j = i;
            count = 0;
            while (j < n)
            {
                if (bits.test(s[j]))
                {
                    count = max(lenght, count);
                    break;
                }
                else
                {
                    bits.set(s[j]);
                    count++;
                }
                j++;
            }
            lenght = max(lenght, count);
            bits.reset();
        }

        return lenght;
    }
};