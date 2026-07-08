class MinStack {
public:

stack<long long >st;
long long int val=INT_MAX;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push(value);
            val=value;
        }
        else if(value<val){
            long long x = (long long)2*value -val;
            st.push(x);
            val=value;
        }
        else{
            st.push(value);
        }
    }
    
    void pop() {
        if(st.empty())return;
        if(st.top()<val){
            val=2*val-st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top()<val){
            return val;
        }
        return st.top();
    }
    
    int getMin() {
        if(st.empty())return -1;
        return val;
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