#define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        set<vector<int>> hashSet;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int left=j+1, right=n-1;
                while(left<right){
                    long long value=(ll)nums[i]+(ll)nums[j]+(ll)nums[left]+(ll)nums[right];
                    if(value==target){
                        hashSet.insert({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;
                    }
                    else if(value<target){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
            }
        }
        for(vector<int> element:hashSet){
            ans.push_back(element);
        }
        return ans;
    }
};