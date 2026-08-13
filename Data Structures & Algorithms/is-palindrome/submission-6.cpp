class Solution {
public:
    bool isPalindrome(string_view s) {
        auto it_start = s.begin(), it_end = s.end()-1;
        
        while (it_start < it_end)
        {
            while (it_start < it_end && !isalnum(*it_start))
            {
                it_start++;
            }

            while (it_end > it_start && !isalnum(*it_end))
            {
                it_end--;
            }

            if (it_start >= it_end) break;
            if (tolower(*it_start) != tolower(*it_end)) return false;
            it_start++;
            it_end--;
        }

        return true;
    }
};