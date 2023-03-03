class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int total_sum=0;
            for(int num: nums){
                    total_sum+=num;
            }
            int prefix_sum=0;
            vector<int> ans;
            for(int num:nums){
                    prefix_sum+=num;
                    total_sum-=num;
                    ans.push_back(num);
                    if(prefix_sum>total_sum){
                            break;
                    }
            }
            return ans;
    }
};