class MinStack {
private:
    stack<int> stack;
    vector<int> min;

public:
    MinStack() {
    }

    void push(int val) {
        if (stack.size() < 1) min.push_back(val);
        else if (val < min[min.size() - 1]) min.push_back(val);
        else min.push_back(min[min.size() - 1]);
        stack.push(val);
    }

    void pop() {
        stack.pop();
        min.pop_back();
    }

    int top() {
        return stack.top();
    }

    int getMin() {
        return min[min.size() - 1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
