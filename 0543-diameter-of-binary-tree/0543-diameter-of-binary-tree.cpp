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
                if(root==NULL){
                        return 0;
                }
                int leftHeight=getHeight(root->left);
                int rightHeight=getHeight(root->right);
                return max(leftHeight,rightHeight)+1;
        }
public:
    int diameterOfBinaryTree(TreeNode* root) {
            if(root==NULL)return 0;
        int leftHeight=getHeight(root->left);
        int rightHeight=getHeight(root->right);
        return max(leftHeight+rightHeight,max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
    }
};