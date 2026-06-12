class Solution {
public:
    int findNthDigit(int n) {
        long long digit_length = 1;
        long long count = 9;        
        long long start = 1;
        while (n > digit_length * count) {
            n -= digit_length * count;
            digit_length++;
            count *= 10;
            start *= 10;
    }
    long long target_num = start + (n - 1) / digit_length;
    string s = to_string(target_num);
        int index = (n - 1) % digit_length;

        return s[index] - '0';
    }
};