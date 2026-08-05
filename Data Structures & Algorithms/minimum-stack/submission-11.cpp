class MinStack {
private:
    std::vector<int> myStack;
    std::vector<int> myMin;
public:
    MinStack() {
        myStack.reserve(25);
        myMin.reserve(25);
    }

    void push(int val) {
        if (myStack.empty() || val <= myMin.back()) myMin.push_back(val);
        myStack.push_back(val);
    }

    void pop() {
        if (myStack.back() == myMin.back()) myMin.pop_back();
        myStack.pop_back();
    }

    int top() {
        return myStack.back();
    }

    int getMin() {
        return myMin.back();
    }
};