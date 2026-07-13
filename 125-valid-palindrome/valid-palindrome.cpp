class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // Move the left pointer forward if the character is not alphanumeric
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            // Move the right pointer backward if the character is not alphanumeric
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            
            // Compare characters by converting them to lowercase
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
};