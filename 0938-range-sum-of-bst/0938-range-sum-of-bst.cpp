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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL){
                return 0;
        }
            int ans=0;
            if(root->val<=high and root->val>=low)ans+=root->val;
            if(root->val==low)return ans+rangeSumBST(root->right,low,high);
            else if(root->val==high) return ans+rangeSumBST(root->left,low,high);
            else return ans+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
    }
};