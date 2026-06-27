class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int result = 0;
        long long number = 0;
        int sign = 1;
        for(int i = 0; i<s.length(); i++){
            char c = s[i];
            if(isdigit(c)){
                number = number * 10 + (c - '0');
            }
            else if(c== '+'){
                result += sign * number;
                number = 0;
                sign =1;
            }
            else if( c =='-'){
                 result += sign * number;
                number = 0;
                sign =-1;
            }
            else if (c == '(') {
                // Push the current result and sign onto the stack
                st.push(result);
                st.push(sign);
                
                // Reset for the sub-expression inside parentheses
                result = 0;
                sign = 1;
            } 
            else if (c == ')') {
                result += sign * number;
                number = 0;

                // Pop sign first, then the previous result
                int prevSign = st.top(); st.pop();
                int prevResult = st.top(); st.pop();

                result = prevResult + prevSign * result;
            }
        }

        // Add the last number if there's any remaining
        result += sign * number;
        return result;
        
    }
};