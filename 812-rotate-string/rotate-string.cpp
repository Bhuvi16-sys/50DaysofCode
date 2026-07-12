class Solution {
public:
    bool rotateString(string s, string goal) {
        // If the lengths are different, s can never be rotated into goal
        if (s.length() != goal.length()) {
            return false;
        }
        
        // Concatenating s with itself contains all possible rotations of s
        string doubled = s + s;
        
        // Check if goal is a substring of the doubled string
        return doubled.find(goal) != string::npos;
    }
};