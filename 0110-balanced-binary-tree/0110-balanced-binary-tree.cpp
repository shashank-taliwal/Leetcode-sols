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
        int getHeight(TreeNode* root){
                if(root==NULL)return 0;
                return 1+max(getHeight(root->left),getHeight(root->right));
        }
public:
    bool isBalanced(TreeNode* root) {
            if(root==NULL)return true;
        return isBalanced(root->left) and isBalanced(root->right) and abs(getHeight(root->left)-getHeight(root->right))<=1;
    }
};