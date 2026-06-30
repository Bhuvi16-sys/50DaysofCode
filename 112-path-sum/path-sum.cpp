/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base case: empty node
        if (root == nullptr) {
            return false;
        }
        
        // Base case: leaf node, check if the remaining sum matches the node's value
        if (root->left == nullptr && root->right == nullptr) {
            return root->val == targetSum;
        }
        
        // Recursive case: update targetSum and check both left and right subtrees
        int remainingSum = targetSum - root->val;
        return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
    }
};