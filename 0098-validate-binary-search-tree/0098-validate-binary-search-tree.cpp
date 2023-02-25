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
        bool util(TreeNode* root, long long lower_value, long long upper_value){
                if(root->val<lower_value or root->val>upper_value){
                        return false;
                }
                if(!root->left and !root->right and root->val>=lower_value and root->val<=upper_value){
                        return true;
                }
                bool ans=true;
                if(root->left){
                        ans=ans and util(root->left, lower_value, (long long)root->val-1);
                }
                if(root->right){
                        ans=ans and util(root->right,(long long)root->val+1, upper_value);
                }
                return ans;
        }
public:
    bool isValidBST(TreeNode* root) {
        return util(root,-1e10,1e10);
    }
};