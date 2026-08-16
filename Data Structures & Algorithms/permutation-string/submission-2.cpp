class Solution {
public:
    bool checkInclusion(string_view s1, string_view s2) {
        size_t size_s1 = s1.size();
        size_t size_s2 = s2.size();

        if (size_s1 > size_s2) return false;

        int32_t count_s1[26] = { 0 };
        for (const char c : s1)
            count_s1[c - 'a']++;

        size_t left = 0, right = 0;

        for (; right < size_s1; right++)
            count_s1[s2[right] - 'a']--;

        while(right < size_s2)
        {
            for (const int32_t i : count_s1)
            {
                if (i != 0)
                {
                    count_s1[s2[right] - 'a']--;
                    count_s1[s2[left] - 'a']++;
                    break;
                }
            }
            right++;
            left++;
        }

        for (const int32_t i : count_s1)
        {
            if (i != 0)
            {
                return false;
            }
        }

        return true;
    }
};