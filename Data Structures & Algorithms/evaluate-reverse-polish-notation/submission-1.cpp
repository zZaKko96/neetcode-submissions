class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> myStack;

        for (string_view str : tokens)
        {
            int val1, val2;
            if (str == "+")
            {
                val1 = myStack.top();
                myStack.pop();
                val2 = myStack.top();
                myStack.pop();

                myStack.push(val1 + val2);
            }
            else if (str == "-")
            {
                val1 = myStack.top();
                myStack.pop();
                val2 = myStack.top();
                myStack.pop();

                myStack.push(val2 - val1);
            }
            else if (str == "*")
            {
                val1 = myStack.top();
                myStack.pop();
                val2 = myStack.top();
                myStack.pop();

                myStack.push(val1 * val2);
            }
            else if(str == "/")
            {
                val1 = myStack.top();
                myStack.pop();
                val2 = myStack.top();
                myStack.pop();

                myStack.push(val2 / val1);
            }
            else myStack.push(stoi(str.data()));
        }
        return myStack.top();
    }
};