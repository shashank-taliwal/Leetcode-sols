class Solution {
public:
    int rob(vector<int>& nums) {
       int n=nums.size();
        if(n==1)return nums.back();
        int val1=rob(nums,0,n-2);
        int val2=rob(nums,1,n-1);
        return max(val1,val2);
    }
private:
    int rob(vector<int>&nums, int start, int last){
        int n=last-start+1;
        if(n==1)return nums[start];
        if(n==2)return max(nums[start],nums[start+1]);
        vector<int> dp(n);
        dp[0]=nums[start];
        dp[1]=max(nums[start],nums[start+1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-2]+nums[start+i],dp[i-1]);
        }
        return dp.back();
    }
};