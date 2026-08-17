class Solution {
public:
    struct ArrayWithEmptyCheck
    {
        int32_t countOfChars[58] = { 0 };
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

        bool RemoveWithCheck(size_t index)
        {
            if (!bitsOfChars.test(index)) return false;

            if (countOfChars[index] == 1)
                countOfNoEmpties--;

            countOfChars[index]--;
            return true;
        }

        bool AddWithCheck(size_t index)
        {
            if (!bitsOfChars.test(index)) return false;

            if (countOfChars[index] == 0)
                countOfNoEmpties++;

            countOfChars[index]++;
            return true;
        }

        bool Empty() const { return !countOfNoEmpties; }
    };

    string minWindow(string_view s, string_view t) {
        string_view minimumSubString = "";
        ArrayWithEmptyCheck check;

        for (const char c : t)
            check.AddNew(c - 'A');

        auto left = s.begin(), right = s.begin();
        vector<decltype(left)> placesToJump;
        placesToJump.reserve(s.size());
        size_t placesToJump_indexPop = 0;

        for (; right != s.end(); right++)
        {
            if (check.RemoveWithCheck(*right - 'A'))
                placesToJump.push_back(right);

            while (check.Empty() && left <= right)
            {
                left = placesToJump[placesToJump_indexPop];
                placesToJump_indexPop++;

                string_view current = string_view(left, right + 1);
                if (minimumSubString.empty() || current.size() < minimumSubString.size())
                    minimumSubString = current;
                if (check.AddWithCheck(*left - 'A'))
                    left++;
            }
        }

        return string(minimumSubString);
    }
};