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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        //trav<ese to find key
        if(key<root->val){
            root->left = deleteNode(root->left, key);

        }else if(key > root->val){
            root->right = deleteNode(root->right, key);

        }else{
            //no child or only bone child
            if(!root->left) return root->right;
            if(!root->right) return root->left;
        
        //find min value node in right subtree
        TreeNode* minNode = root->right;
        while(minNode->left){
            minNode = minNode->left;
        }
        root->val = minNode->val;
        root->right = deleteNode(root->right, minNode->val);
        }
        return root;
    }
};