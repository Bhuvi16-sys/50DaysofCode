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
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr){
            return -1;
        }
        int leftcount = countnode(root->left);
        if(leftcount == k-1){
            return root->val;
        }
        else if(leftcount >= k){
            return kthSmallest(root->left, k);

        }
        else{
            return kthSmallest(root->right, k - leftcount - 1 );
        }
    }
    private:
    int countnode(TreeNode* node){
        if(node==nullptr){
            return 0;
        }
        return  1 + countnode(node ->left) + countnode(node->right);
    }
};