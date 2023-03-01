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
        void pathSumUtil(TreeNode* root, long long targetSum, unordered_map<long long,long long> prefixSums, long long current_sum, int& ans){
                current_sum+=(long long)root->val;
                if(current_sum==targetSum){
                        ans+=1;
                        ans+=prefixSums[0];
                }
                else{
                        long long comp=current_sum-targetSum;
                        if(prefixSums.find(comp)!=prefixSums.end()){
                                ans+=prefixSums[comp];
                        }
                }
                prefixSums[current_sum]+=1;
                if(root->left)pathSumUtil(root->left,targetSum,prefixSums,current_sum,ans);
                if(root->right)pathSumUtil(root->right,targetSum,prefixSums,current_sum,ans);
                return;
        }
public:
    int pathSum(TreeNode* root, int targetSum) {
            if(root==NULL)return 0;
        unordered_map<long long,long long> prefixSums;
            int ans=0;
        pathSumUtil(root,(long long)targetSum,prefixSums,(long long)0,ans);
            return ans;
    }
};