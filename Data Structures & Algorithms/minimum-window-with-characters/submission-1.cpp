class Solution {
public:
    struct ArrayWithEmptyCheck
    {
        uint32_t countOfChars[58] = { 0 };
        bitset<58> bitsOfChars;
        uint32_t countOfNoEmpties = 0;

        void AddNew(size_t index)
        {
            if (countOfChars[index] == 0)
            {
                countOfNoEmpties++;
                bitsOfChars.set(index);
            }

            countOfChars[index]++;
        }

        void RemoveWithCheck(size_t index)
        {
            if (!bitsOfChars.test(index)) return;

            if (countOfChars[index] == 1)
                countOfNoEmpties--;

            countOfChars[index]--;
        }

        void AddWithCheck(size_t index)
        {
            if (!bitsOfChars.test(index)) return;

            if (countOfChars[index] == 0)
                countOfNoEmpties++;

            countOfChars[index]++;
        }

        bool Empty() const { return !countOfNoEmpties; }
    };

    string minWindow(string_view s, string_view t) {
        string_view minimumSubString = "";
        ArrayWithEmptyCheck check;

        for (const char c : t)
            check.AddNew(c - 'A');

        auto left = s.begin(), right = s.begin();

        for (; right != s.end(); right++)
        {
            check.RemoveWithCheck(*right - 'A');

            while (check.Empty() && left <= right)
            {
                string_view current = string_view(left, right + 1);
                if (minimumSubString.empty() || current.size() < minimumSubString.size())
                    minimumSubString = current;

                check.AddWithCheck(*left - 'A');
                left++;
            }
        }

        return string(minimumSubString);
    }
};