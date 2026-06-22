#include <stack>

class MyQueue {
private:
    std::stack<int> input_stack;
    std::stack<int> output_stack;

    // Helper function to shift elements from input to output stack when needed
    void shiftStacks() {
        if (output_stack.empty()) {
            while (!input_stack.empty()) {
                output_stack.push(input_stack.top());
                input_stack.pop();
            }
        }
    }

public:
    MyQueue() {
        // Constructor
    }
    
    // Push element x to the back of queue.
    void push(int x) {
        input_stack.push(x);
    }
    
    // Removes the element from the front of queue and returns it.
    int pop() {
        shiftStacks();
        int frontElement = output_stack.top();
        output_stack.pop();
        return frontElement;
    }
    
    // Get the front element.
    int peek() {
        shiftStacks();
        return output_stack.top();
    }
    
    // Returns whether the queue is empty.
    bool empty() {
        return input_stack.empty() && output_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */