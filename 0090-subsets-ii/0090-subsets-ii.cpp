class Solution {
    void util(vector<int>& nums, int index, int n, vector<int> curr, set<vector<int>>& ansSet){
        if(index==n){
            sort(curr.begin(),curr.end());
            ansSet.insert(curr);
            return;
        }
        util(nums,index+1,n,curr,ansSet);
        curr.push_back(nums[index]);
        util(nums,index+1,n,curr,ansSet);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<int> curr;
        set<vector<int>> ansSet;
        util(nums,0,n,curr, ansSet);
        vector<vector<int>> ans;
        for(vector<int> arr: ansSet){
            ans.push_back(arr);
        }
        return ans;
    }
};