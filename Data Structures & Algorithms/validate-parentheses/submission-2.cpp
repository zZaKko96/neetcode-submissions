class Solution {
public:
    bool isValid(string_view s) {
        std::stack<char> myStack;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') 
                myStack.push(s[i]);
            else if (s[i] == ')')
            {
                if (!myStack.empty())
                {
                    if (myStack.top() == '(')
                        myStack.pop();
                    else return false;
                }
                else return false;
            }
            else if (s[i] == ']')
            {
                if (!myStack.empty())
                {
                    if (myStack.top() == '[')
                        myStack.pop();
                    else return false;
                }
                else return false;
            }
            else if (s[i] == '}')
            {
                if (!myStack.empty())
                {
                    if (myStack.top() == '{')
                        myStack.pop();
                    else return false;
                }
                else return false;
            }
        }
        if (!myStack.empty()) return false;
        return true;
    }
};