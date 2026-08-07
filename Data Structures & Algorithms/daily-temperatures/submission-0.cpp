class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>answers(temperatures.size(),0);
        vector<int>myStack;
        myStack.reserve(temperatures.size());

        for (size_t i = 0; i < temperatures.size(); i++)
        {
            if (myStack.empty()) myStack.push_back(i);
            else if (temperatures[i] < temperatures[myStack.back()]) myStack.push_back(i);
            else
            {
                while (!myStack.empty() && temperatures[i] > temperatures[myStack.back()])
                {
                    answers[myStack.back()] = i - myStack.back();
                    myStack.pop_back();
                }
                myStack.push_back(i);
            }
        }

        return answers;
    }
};