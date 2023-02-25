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
    bool hasPathSum(TreeNode* root, int targetSum) {
             if(root==NULL){
                    return false;
            }
        if(targetSum-root->val==0){
                if(root->left==NULL and root->right==NULL){
                        return true;
                }
        }
            
            bool leftAns=false,rightAns=false;
            if(root->left)leftAns=hasPathSum(root->left, targetSum-root->val);
            if(root->right)rightAns=hasPathSum(root->right, targetSum-root->val);
            return leftAns or rightAns;
    }
};