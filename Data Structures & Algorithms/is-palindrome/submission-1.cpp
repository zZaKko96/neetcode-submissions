class Solution {
public:
    bool isPalindrome(string_view s) {
        auto it_start = s.begin(), it_end = s.end()-1;
        
        while (it_start < it_end)
        {
            while (it_start != s.end() && !((*it_start >= 48 && *it_start <= 57)
                || (*it_start >= 65 && *it_start <= 90)
                || (*it_start >= 97 && *it_start <= 122)))
            {
                it_start++;
            }

            while (it_end != s.begin() && !((*it_end >= 48 && *it_end <= 57)
                || (*it_end >= 65 && *it_end <= 90)
                || (*it_end >= 97 && *it_end <= 122)))
            {
                it_end--;
            }

            if (it_start == s.end() && it_end == s.begin()) return true;
            if (tolower(*it_start) != tolower(*it_end)) return false;
            it_start++;
            it_end--;
        }

        return true;
    }
};