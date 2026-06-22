class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char c : s) {
            // If it's an opening bracket, push it to the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // If it's a closing bracket
            else {
                // If stack is empty, we have a closing bracket without a matching opening one
                if (st.empty()) return false;
                
                char top = st.top();
                // Check for a mismatch
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
                
                // If it matches, pop the opening bracket
                st.pop();
            }
        }
        
        // If the stack is empty, all brackets were matched perfectly
        return st.empty();
    }
};