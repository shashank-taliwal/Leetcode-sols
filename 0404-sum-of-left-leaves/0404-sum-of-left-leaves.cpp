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
        int sumUtil(TreeNode* root, int dir){
                //dir =-1 left, dir=1 right
                if(root==NULL){
                        return 0;
                }
                if(root->left==NULL and root->right==NULL){
                        if(dir==-1){
                                return root->val;
                        }
                        else{
                                return 0;
                        }
                }
                return sumUtil(root->left,-1)+sumUtil(root->right,1);
                
        }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int ans=sumUtil(root,0);
            return ans;
    }
};