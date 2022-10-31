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
        map<int,int> height_subtree;
        map<int, int> level;
        int getHeight(TreeNode* root){
                if(height_subtree[root->val]>0) return height_subtree[root->val];
                if(root->left==NULL and root->right==NULL){
                       return height_subtree[root->val]=0;
                }
                if(root->left==NULL){
                        return height_subtree[root->val]=getHeight(root->right)+1;
                        
                }
                if(root->right==NULL){
                        return height_subtree[root->val]=getHeight(root->left)+1;
                }
                 return height_subtree[root->val]=max(getHeight(root->left),getHeight(root->right))+1;
        }
        vector<vector<int>> getLevel(TreeNode* root){
                // level[root]=0;
                queue<TreeNode*> q;
                vector<vector<int>> v1;
                q.push(root);
                while(!q.empty()){
                        int sz=q.size();
                        vector<int> temp;
                        while(sz--){
                                TreeNode* node=q.front();
                                temp.push_back(node->val);
                                if(node->left)q.push(node->left);
                                if(node->right)q.push(node->right);
                                q.pop();
                        }
                        v1.push_back(temp);
                }
                for(int i=0;i<v1.size();i++){
                        for(int j=0;j<v1[i].size();j++){
                                level[v1[i][j]]=i+1;
                        }
                }
                return v1;
        }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        getHeight(root);
         vector<vector<int>> v1=getLevel(root);
            vector<int> ans;
            int max_height=0;
            for(auto it: height_subtree){
                    max_height=max(max_height,it.second);
            }
        max_height++;
            for(int query:queries){
                    int lvl=level[query];
                    int h=height_subtree[query];
                    int idx=lvl-1;
                    int temp=0;
                    for(int i=0;i<v1[idx].size();i++){
                            // cout<<v1[idx][i]<<endl;
                            if(v1[idx][i]!=query){
                                    if(height_subtree[v1[idx][i]]>=h){
                                            temp=max(temp,max_height);
                                            break;
                                    }
                                    else{
                                            temp=max(temp,height_subtree[v1[idx][i]]+lvl);
                                    }
                            }
                    }
                    ans.push_back(max(temp-1,lvl-2));
            }
            return ans;
            
            
    }
};