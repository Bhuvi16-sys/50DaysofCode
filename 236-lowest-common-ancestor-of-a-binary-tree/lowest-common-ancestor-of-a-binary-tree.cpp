/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if root is null, or we found either p or q
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        
        // Look for p and q in the left and right subtrees
        TreeNode* leftResult = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightResult = lowestCommonAncestor(root->right, p, q);
        
        // If both subtrees returned a non-null value, root is the LCA
        if (leftResult != nullptr && rightResult != nullptr) {
            return root;
        }
        
        // Otherwise, return the non-null side
        return (leftResult != nullptr) ? leftResult : rightResult;
    }
};