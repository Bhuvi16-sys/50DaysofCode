class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = binarySearch(nums, target, true);
        int last = binarySearch(nums, target, false);
        return {first, last};
    }

private:
    int binarySearch(vector<int>& nums, int target, bool isSearchingFirst) {
        int low = 0, high = nums.size() - 1;
        int index = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                index = mid; // Record the potential answer
                if (isSearchingFirst) {
                    high = mid - 1; // Keep looking left
                } else {
                    low = mid + 1;  // Keep looking right
                }
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return index;
    }
};