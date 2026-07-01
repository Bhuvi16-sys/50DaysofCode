class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int totalSubarrays = 0;
        int size = nums.size();
        
        for (int i = 0; i < size; ++i) {
            int currentLcm = nums[i];
            
            for (int j = i; j < size; ++j) {
                // Update LCM using std::gcd from <numeric>
                currentLcm = ((long long)currentLcm * nums[j]) / std::gcd(currentLcm, nums[j]);
                
                // Optimization: If currentLcm exceeds k or doesn't divide k, 
                // any larger subarray containing these elements will also invalid
                if (currentLcm > k || k % currentLcm != 0) {
                    break;
                }
                
                if (currentLcm == k) {
                    totalSubarrays++;
                }
            }
        }
        
        return totalSubarrays;
    }
};