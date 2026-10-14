class MinStack {
public:
    
    stack<int> normal_stack;
    stack<int> min_stack;

    MinStack() {
    }
    
    void push(int val) {
        normal_stack.push(val);
        if (min_stack.size() == 0 || min_stack.top() >= val)  {
            min_stack.push(val);
        }

        else {
            min_stack.push(min_stack.top());
        }
    }
    
    void pop() {
        normal_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return normal_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
