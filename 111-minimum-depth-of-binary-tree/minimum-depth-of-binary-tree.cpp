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
    int minDepth(TreeNode* root) {
        // Base case: Empty tree has a depth of 0
        if (root == nullptr) {
            return 0;
        }
        
        // If the left subtree is empty, we must traverse down the right subtree
        if (root->left == nullptr) {
            return 1 + minDepth(root->right);
        }
        
        // If the right subtree is empty, we must traverse down the left subtree
        if (root->right == nullptr) {
            return 1 + minDepth(root->left);
        }
        
        // If both children exist, pick the minimum depth between the two sides
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};