class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answers(n, 0);
        vector<int> myStack;
        myStack.reserve(n);

        for (int i = 0; i < n; ++i) {
            while (!myStack.empty() && temperatures[i] > temperatures[myStack.back()]) {
                int prevIdx = myStack.back();
                myStack.pop_back();
                answers[prevIdx] = i - prevIdx;
            }
            myStack.push_back(i);
        }

        return answers;
    }
};