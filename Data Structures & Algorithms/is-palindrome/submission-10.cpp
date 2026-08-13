class Solution {
    static constexpr auto LUT = []() {
        std::array<char, 256> table{};
        for (int i = 0; i < 256; ++i) {
            if ((i >= 'a' && i <= 'z') || (i >= '0' && i <= '9')) {
                table[i] = static_cast<char>(i);
            }
            else if (i >= 'A' && i <= 'Z') {
                table[i] = static_cast<char>(i + ('a' - 'A'));
            }
            else {
                table[i] = 0;
            }
        }
        return table;
        }();

public:
    bool isPalindrome(std::string_view s) {
        if (s.empty()) return true;

        const char* left = s.data();
        const char* right = s.data() + s.length() - 1;

        while (left < right) {
            while (left < right && LUT[static_cast<unsigned char>(*left)] == 0) {
                left++;
            }

            while (left < right && LUT[static_cast<unsigned char>(*right)] == 0) {
                right--;
            }

            if (left >= right) break;

            if (LUT[static_cast<unsigned char>(*left)] != LUT[static_cast<unsigned char>(*right)]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};