#include <queue>

class MyStack {
private:
    std::queue<int> q;

public:
    MyStack() {
        // Constructor
    }
    
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
        int sz = q.size();
        
        // Rotate the queue to bring the new element to the front
        for (int i = 0; i < sz - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    // Removes the element on top of the stack and returns it.
    int pop() {
        int top_element = q.front();
        q.pop();
        return top_element;
    }
    
    // Get the top element.
    int top() {
        return q.front();
    }
    
    // Returns whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};