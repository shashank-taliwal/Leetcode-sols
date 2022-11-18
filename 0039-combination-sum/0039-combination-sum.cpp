class Solution {
        void util(vector<int>& candidates, int index, int n, vector<int> current_seq, set<vector<int>>& hashSet, int target){
               if(target==0){
                       hashSet.insert(current_seq);
               }
                if(index>=n){
                        return;
                }
                if(candidates[index]<=target){
                        util(candidates,index+1,n,current_seq,hashSet,target);
                        current_seq.push_back(candidates[index]);
                        util(candidates,index,n,current_seq,hashSet,target-candidates[index]);
                }
                else{
                        return;
                }
        }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
            set<vector<int>> hashSet;
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        util(candidates,0,n,{},hashSet,target);
            for(vector<int> seq: hashSet){
                    ans.push_back(seq);
            }
            return ans;
    }
};