class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;
        st.reserve(tokens.size());

        for (const string& str : tokens) {
            if (str.size() == 1 && !isdigit(str[0])) {
                int b = st.back(); st.pop_back();
                int a = st.back(); st.pop_back();

                switch (str[0]) {
                case '+': st.push_back(a + b); break;
                case '-': st.push_back(a - b); break;
                case '*': st.push_back(a * b); break;
                case '/': st.push_back(a / b); break;
                }
            }
            else {
                int val = 0;
                std::from_chars(str.data(), str.data() + str.size(), val);
                st.push_back(val);
            }
        }

        return st.back();
    }
};