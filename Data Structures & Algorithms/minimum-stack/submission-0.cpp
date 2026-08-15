class MinStack {
private:
    int minn=INT_MAX;
    stack<int> st;
    stack<int> min_stack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(min_stack.empty()){
            min_stack.push(val);
        }
        else{
            min_stack.push(min(val,min_stack.top()));
        }
    }
    
    void pop() {
        if(!st.empty()){
            st.pop();
            min_stack.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
