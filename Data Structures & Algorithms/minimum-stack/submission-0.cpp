class MinStack {
    stack<int> normal;
    stack<int> order;
public:
    MinStack() {
        
    }
    
    void push(int val) {
       normal.push(val);
       val=min(val, order.empty()?val:order.top());
       order.push(val);
    }
    
    void pop() {
        normal.pop();
        order.pop();
    }
    
    int top() {
        return normal.top();
    }
    
    int getMin() {
        return order.top();
    }
};
