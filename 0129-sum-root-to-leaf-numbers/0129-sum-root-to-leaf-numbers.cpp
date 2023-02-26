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
        int getNumber(vector<int> current_number){
                int ans=0;
                for(int num:current_number){
                        ans=ans*10+num;
                }
                return ans;
        }
        void getNumbers(TreeNode* root, vector<int>& numbers, vector<int> current_number){
                if(root==NULL)return;
                if(root->left==NULL and root->right==NULL){
                        current_number.push_back(root->val);
                        int number=getNumber(current_number);
                        numbers.push_back(number);
                        return;
                }
                current_number.push_back(root->val);
                getNumbers(root->left,numbers,current_number);
                getNumbers(root->right, numbers, current_number);
                current_number.pop_back();
                return;
        }
public:
    int sumNumbers(TreeNode* root) {
            if(root==NULL)return 0;
        vector<int> numbers;
        getNumbers(root,numbers,{});
        int sum=0;
            for(int i=0;i<numbers.size();i++){
                    sum+=numbers[i];
            }
            return sum;
    }
};