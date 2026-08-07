class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;
        st.reserve(tokens.size());

        for (string_view str : tokens) {
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
                st.push_back(stoi(string(str)));
            }
        }

        return st.back();
    }
};