class MinStack {
    stack<pair<int,int>> v;
public:
    MinStack() {
    }
    
    void push(int value) {
        if(v.empty()){
            v.push({value,value});
        }else{
            v.push({value,min(value,v.top().second)});
        }
    }
    
    void pop() {
        v.pop();
    }
    
    int top() {
        return v.top().first;
    }
    
    int getMin() {
        return v.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */