#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numMap; // stores: {number, index}
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // If complement is found, return its index and current index
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            
            // Otherwise, insert the current number and its index into the map
            numMap[nums[i]] = i;
        }
        
        return {}; // Return empty vector if no solution is found
    }
};