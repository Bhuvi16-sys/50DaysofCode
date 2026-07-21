class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int res = nums[0];
        for(int x : nums){
            res = std::gcd(res, x);
            if(res==1) return true;
        }
        return res==1;
    }
};