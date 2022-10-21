class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int reach=0;
        for(reach;i<n and i<=reach; i++){
            reach=max(i+nums[i],reach);
        }
        return i>=n;
    }
};