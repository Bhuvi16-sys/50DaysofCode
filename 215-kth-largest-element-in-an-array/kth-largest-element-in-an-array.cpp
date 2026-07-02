#include <vector>
#include <queue>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        // Min-heap to store the k largest elements seen so far
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        
        for (int num : nums) {
            minHeap.push(num);
            
            // If the heap grows larger than k, remove the smallest element
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        // The top of the heap is the k-th largest element
        return minHeap.top();
    }
};