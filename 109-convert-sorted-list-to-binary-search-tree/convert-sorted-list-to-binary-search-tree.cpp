class Solution {
private:
    // Simple recursive helper using array boundaries
    TreeNode* buildBST(const vector<int>& nums, int row, int col) {
        // Base case: if the range is invalid, there are no elements left
        if (row > col) {
            return nullptr;
        }
        
        // Find the exact middle index
        int mid = row + (col - row) / 2;
        
        // Create the root node with the middle value
        TreeNode* root = new TreeNode(nums[mid]);
        
        // Recursively build the left and right halves
        root->left = buildBST(nums, row, mid - 1);
        root->right = buildBST(nums, mid + 1, col);
        
        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        
        // Step 1: Copy everything from the linked list into an array
        while (head != nullptr) {
            nums.push_back(head->val);
            head = head->next;
        }
        
        // Step 2: Build the BST using the array boundaries [0, size - 1]
        return buildBST(nums, 0, nums.size() - 1);
    }
};