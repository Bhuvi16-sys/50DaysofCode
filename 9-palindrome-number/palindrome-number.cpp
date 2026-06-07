class Solution {
public:
    bool isPalindrome(int x) {
        //edge case for negative number
        if( x < 0){
            return false;

        }
        long long reversedNum = 0;
        int originalnum = x;
        while(originalnum != 0){
            int digit = originalnum % 10;
            reversedNum = reversedNum * 10 + digit;
            originalnum /= 10;
        }
        return reversedNum == x;
    }
};