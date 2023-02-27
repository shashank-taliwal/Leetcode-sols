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
struct RobResult{
        int included;
        int excluded;
        RobResult(int _inc, int _exc){
                included=_inc;
                excluded=_exc;
        }
};
class Solution {
        struct RobResult robUtil(TreeNode* root){
                if(root==NULL){
                        return RobResult(0,0);
                }
                struct RobResult leftRobResult=robUtil(root->left);
                struct RobResult rightRobResult=robUtil(root->right);
                
                //included
                int included=root->val+leftRobResult.excluded+rightRobResult.excluded;
                //excluded
                int excluded=max(leftRobResult.excluded, leftRobResult.included)+max(rightRobResult.included, rightRobResult.excluded);
                return RobResult(included, excluded);
        }
public:
    int rob(TreeNode* root) {
        struct RobResult ans=robUtil(root);
            return max(ans.included, ans.excluded);
    }
};