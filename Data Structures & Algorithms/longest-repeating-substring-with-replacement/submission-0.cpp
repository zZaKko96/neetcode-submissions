class Solution {
public:
    struct arrayCountWithMax
    {
        uint32_t count[26] = { 0 };
        vector<uint32_t> max_freq;

        void Plus(size_t index)
        {
            count[index]++;
            if (max_freq.empty() || count[index] > max_freq.back())
                max_freq.emplace_back(count[index]);
        }

        void Minus(size_t index)
        {
            if (!max_freq.empty() && count[index] == max_freq.back())
                max_freq.pop_back();
            count[index]--;
        }
    };
    int characterReplacement(string_view s, int k) {
        int length = 0;

        size_t size = s.size();

        arrayCountWithMax count;
        count.max_freq.reserve(size);

        for (size_t left = 0, right = 0; right < size; right++)
        {
            count.Plus(s[right] - 'A');
            if (int newLenght = (right - left + 1); newLenght - count.max_freq.back() <= k)
                length = max(length,newLenght);
            else
            {
                count.Minus(s[left] - 'A');
                left++;
            }
        }

        return length;
    }
};