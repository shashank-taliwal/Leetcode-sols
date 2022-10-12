class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
            int current_limit=0,ans=0,i=0,limit=0;
            if(n==1)return 0;
            while(i<n-1){
                    limit=max(limit,i+nums[i]);
                       if(i==current_limit){
                            ans++;
                            current_limit=limit;
                    }
                    i++;
            }
            return ans;
    }
};