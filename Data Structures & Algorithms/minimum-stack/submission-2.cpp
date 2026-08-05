class MinStack {
private:
    stack<int, std::vector<int>> myStack;
    stack<int, std::vector<int>> myMin;
public:
    MinStack() {

    }

    void push(int val) {
        if (myStack.empty() || val <= myMin.top()) myMin.push(val);
        myStack.push(val);
    }

    void pop() {
        if (myStack.top() == myMin.top()) myMin.pop();
        myStack.pop();
    }

    int top() {
        return myStack.top();
    }

    int getMin() {
        return myMin.top();
    }
};