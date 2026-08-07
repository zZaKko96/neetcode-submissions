class Solution {
public:
    unordered_map<string, int(*)(int, int)>operations{
        {"+",[](int a, int b) {return a + b; }},
    {"-",[](int a, int b) {return a - b; }},
    { "*", [](int a, int b) {return a * b; } },
        {"/",[](int a, int b) {return a / b; }} };

    int evalRPN(vector<string>& tokens) {
        std::vector<int> myStack;
        //myStack.reserve(tokens.size());

        for (string_view str : tokens)
        {
            int val1, val2;
            if (str == "+" || str == "-" || str == "*" || str == "/")
            {
                val2 = myStack.back();
                myStack.pop_back();
                val1 = myStack.back();
                myStack.pop_back();
                
                myStack.push_back(operations.find(str.data())->second(val1,val2));
            }
            else myStack.push_back(stoi(str.data()));
        }
        return myStack.back();
    }
};