class Solution {
    struct WindowTracker {
        int32_t count[26] = { 0 };
        int32_t positive_count = 0;

        void add(unsigned char c) {
            if (count[c] == 0) positive_count++;
            count[c]++;
        }

        void remove(unsigned char c) {
            if (count[c] == 1) positive_count--;
            count[c]--;
        }

        bool is_match() const {
            return positive_count == 0;
        }
    };

public:
    bool checkInclusion(string_view s1, string_view s2) {
        size_t n1 = s1.size();
        size_t n2 = s2.size();

        if (n1 > n2) return false;

        WindowTracker tracker;

        for (unsigned char c : s1) {
            tracker.add(c - 'a');
        }

        const char* left = s2.data();
        const char* right = s2.data();
        const char* end = s2.data() + n2;

        while (right < left + n1) {
            tracker.remove(*right - 'a');
            right++;
        }

        if (tracker.is_match()) return true;

        while (right < end) {
            tracker.remove(*right - 'a');
            tracker.add(*left - 'a');

            if (tracker.is_match()) return true;

            right++;
            left++;
        }

        return false;
    }
};