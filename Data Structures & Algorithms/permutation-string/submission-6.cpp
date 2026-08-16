class Solution {
public:
    struct ArrayWithCheck
    {
        int32_t count[26] = { 0 };
        size_t countOfNoZero = 0;

        void Plus(size_t index)
        {
            if (count[index] == 0) countOfNoZero++;
            else if (count[index] == -1) countOfNoZero--;
            count[index]++;
        }

        void Minus(size_t index)
        {
            if (count[index] == 1) countOfNoZero--;
            else if (count[index] == 0) countOfNoZero++;
            count[index]--;
        }

        bool Empty() const { return countOfNoZero == 0; }
    };

    bool checkInclusion(string_view s1, string_view s2) {
        size_t size_s1 = s1.size();
        size_t size_s2 = s2.size();

        if (size_s1 > size_s2) return false;

        ArrayWithCheck count_s1;
        for (const char c : s1)
            count_s1.Plus(c - 'a');

        size_t left = 0, right = 0;

        for (; right < size_s1; right++)
            count_s1.Minus(s2[right] - 'a');

        while(right < size_s2)
        {
            if (!count_s1.Empty())
            {
                count_s1.Minus(s2[right] - 'a');
                count_s1.Plus(s2[left] - 'a');
            }
            else return true;
            right++;
            left++;
        }
        return count_s1.Empty();
    }
};