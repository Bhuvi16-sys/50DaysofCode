class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st; // Stores indices of opening parentheses '('
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop(); // Found a valid pair
                } else {
                    s[i] = '*'; // Mark invalid closing parenthesis for removal
                }
            }
        }
        
        // Any indices left in the stack represent unmatched '('
        while (!st.empty()) {
            s[st.top()] = '*'; // Mark invalid opening parenthesis for removal
            st.pop();
        }
        
        // Rebuild the string ignoring the marked '*' characters
        string result = "";
        for (char c : s) {
            if (c != '*') {
                result += c; 
            }
        }
        
        return result;
    }
};