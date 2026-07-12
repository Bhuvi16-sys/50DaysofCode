class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // Base cases: root is null (not found) or root's value matches val
        if (root == nullptr || root->val == val) {
            return root;
        }
        
        // If the target value is smaller, search the left subtree
        if (val < root->val) {
            return searchBST(root->left, val);
        }
        
        // Otherwise, search the right subtree
        return searchBST(root->right, val);
    }
};