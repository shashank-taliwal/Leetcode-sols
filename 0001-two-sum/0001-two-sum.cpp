class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m1;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int searchValue=target-nums[i];
            if(m1.find(searchValue)!=m1.end()){
                ans.push_back(i);
                ans.push_back(m1[searchValue]);
            }
            else{
                m1[nums[i]]=i;
            }
        }
        return ans;
    }
};