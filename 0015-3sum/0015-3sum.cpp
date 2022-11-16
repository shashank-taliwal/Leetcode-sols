class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> hashSet;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            int left=i+1,right=n-1;
            while(left<right){
                int value=nums[i]+nums[left]+nums[right];
                if(value==0){
                    hashSet.insert({nums[i],nums[left],nums[right]});
                        left++;
                    right--;
                }
                else if(value<0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        for(auto it: hashSet){
            ans.push_back(it);
        }
        return ans;
    }
};