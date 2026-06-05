class Solution {
public:
    int addDigits(int num) {

        if(num==0)return 0;//edge case
        if(num % 9 ==0) return 9; // if we divide by 9 it be be zero and return 9
        return num % 9;//if we divide any number by 9 it will give the sum of all digit into a single digit
    }
};