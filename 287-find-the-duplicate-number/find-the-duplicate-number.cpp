class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Step 1: Walk until the slow and fast pointers meet
        int tortoise = nums[0];
        int hare = nums[0];
        
        do {
            tortoise = nums[tortoise];       // 1 step
            hare = nums[nums[hare]];         // 2 steps
        } while (tortoise != hare);
        
        // Step 2: Reset tortoise to start, move both at 1 step/turn
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];       // 1 step
            hare = nums[hare];               // 1 step
        }
        
        return tortoise; // This is the duplicate entrance
    }
};