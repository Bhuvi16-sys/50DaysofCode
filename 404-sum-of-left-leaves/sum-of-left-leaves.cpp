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
private:
    int dfs(TreeNode* node, bool isLeft) {
        if (!node) return 0;
        
        // Check if the current node is a leaf node
        if (!node->left && !node->right) {
            return isLeft ? node->val : 0;
        }
        
        // Recursively traverse left and right subtrees
        return dfs(node->left, true) + dfs(node->right, false);
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        // The root itself is not considered a left child of any node
        return dfs(root, false);
    }
};