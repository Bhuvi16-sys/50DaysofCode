class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int totalprimebitcount  = 0;
        for(int i = left;i<=right;i++){
            int setBits = __builtin_popcount(i);
            if (setBits == 2 || setBits == 3 || setBits == 5 || setBits == 7 || 
                setBits == 11 || setBits == 13 || setBits == 17 || setBits == 19) {
                totalprimebitcount++;
                }
        }
        return totalprimebitcount;
    }
};