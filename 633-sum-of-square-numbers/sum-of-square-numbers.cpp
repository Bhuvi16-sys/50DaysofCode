class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0;
        long long right = sqrt(c);
        while(left <= right){
            long long curr_sum = (left * left) + (right * right);
            if(curr_sum == c){
                return true;
            }else if(curr_sum< c){
                left++;

            }
            else{
                right--;
            }
        }
        return false;
    }
};