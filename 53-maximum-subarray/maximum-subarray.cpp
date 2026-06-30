class Solution {
public:
    int maxSubArray(vector<int>& nums){
        if (nums.empty()) return 0;
        int maxSum = nums[0];
        int currentSum = nums[0];

        for (size_t i = 1; i < nums.size(); i++) {
            
            currentSum = std::max(nums[i], currentSum + nums[i]);
            maxSum = std::max(maxSum, currentSum);
        }

        return maxSum;
    }
};