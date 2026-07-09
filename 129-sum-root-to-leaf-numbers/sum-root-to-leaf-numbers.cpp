/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    int calculateSum(TreeNode* node, int currentSum) {
        if (node == nullptr) {
            return 0;
        }
        
        // Update the current path number
        currentSum = currentSum * 10 + node->val;
        
        // If it's a leaf node, return the accumulated path sum
        if (node->left == nullptr && node->right == nullptr) {
            return currentSum;
        }
        
        // Otherwise, recurse for left and right subtrees
        int leftSum = calculateSum(node->left, currentSum);
        int rightSum = calculateSum(node->right, currentSum);
        
        return leftSum + rightSum;
    }
public:
    int sumNumbers(TreeNode* root) {
        return calculateSum(root, 0);
    }
};