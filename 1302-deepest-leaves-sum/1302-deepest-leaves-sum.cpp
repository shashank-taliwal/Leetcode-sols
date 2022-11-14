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
        vector<vector<int>> get_LOT(TreeNode* root){
                queue<TreeNode*> q;
                vector<vector<int>> ans;
                q.push(root);
                while(!q.empty()){
                        vector<int> level;
                        int sz=q.size();
                        while(sz--){
                                auto node=q.front();
                                level.push_back(node->val);
                                q.pop();
                                if(node->left)q.push(node->left);
                                if(node->right)q.push(node->right);
                                
                        }
                        ans.push_back(level);
                }
                return ans;
        }
public:
    int deepestLeavesSum(TreeNode* root) {
        vector<vector<int>> level_order_traversal=get_LOT(root);
        int n=level_order_traversal.size();
            int sum=0;
            for(int i=0;i<level_order_traversal[n-1].size();i++){
                    sum+=level_order_traversal[n-1][i];
            }
            return sum;
    }
};