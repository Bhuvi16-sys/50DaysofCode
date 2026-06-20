#include <stack>
#include <algorithm>

class MinStack {
private:
    // Stores pair of {current_value, minimum_so_far}
    std::stack<std::pair<int, int>> st;

public:
    MinStack() {
        // Constructor initializes the stack object
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            // The new minimum is the smaller of the current value and the previous minimum
            int current_min = std::min(val, st.top().second);
            st.push({val, current_min});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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