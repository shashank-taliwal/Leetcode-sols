class Solution {
        void f(int sum, int qty_allowed,vector<int>& possible_numbers, int last_index_accessed,set<vector<int>>& s1, vector<int> chosen){
                if(sum<0){
                        return;
                }
                if(last_index_accessed==0 and sum>0){
                        return;
                }
                if(qty_allowed==0 and sum==0){
                        s1.insert(chosen);
                        return;
                }
                for(int i=last_index_accessed-1;i>=0;i--){
                        chosen.push_back(possible_numbers[i]);
                        f(sum-possible_numbers[i],qty_allowed-1,possible_numbers,i,s1,chosen);
                        chosen.pop_back();
                }
        }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>> s1;
            vector<vector<int>> ans;
            vector<int> possible_numbers={1,2,3,4,5,6,7,8,9};
            f(n,k,possible_numbers,9,s1,{});
            for(vector<int> temp: s1){
                    ans.push_back(temp);
            }
            return ans;
    }
};