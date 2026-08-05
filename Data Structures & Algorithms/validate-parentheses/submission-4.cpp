class Solution {
public:
    bool isValid(string_view s) {
        if (s.size() % 2 != 0) return false;

        string st;
        st.reserve(s.size());

        for (const char c : s) {
            if (c == '(')      st.push_back(')');
            else if (c == '[') st.push_back(']');
            else if (c == '{') st.push_back('}');
            else {
                if (st.empty() || st.back() != c) return false;
                st.pop_back();
            }
        }

        return st.empty();
    }
};