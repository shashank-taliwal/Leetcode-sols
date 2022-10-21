class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        if(n==3)return max(nums[0]+nums.back(),nums[1]);
        vector<int> dp(n);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        dp[2]=max(nums[0]+nums[2], nums[1]);
        for(int i=3;i<n;i++){
            int val1=dp[i-2]+nums[i];
            int val2=dp[i-1];
            dp[i]=max(val1,val2);
        }
        return dp.back();
    }
};