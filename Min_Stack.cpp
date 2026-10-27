class MinStack {
    std::stack<int> s;
    std::stack<int> min_s;

public:
    MinStack() {}
    
    void push(int value) {
        s.push(value);
        if (min_s.empty() || value <= min_s.top()) {
            min_s.push(value);
        }
    }
    
    void pop() {
        if (s.top() == min_s.top()) {
            min_s.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_s.top();
    }
};
