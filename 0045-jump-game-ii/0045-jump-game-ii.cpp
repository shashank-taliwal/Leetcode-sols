class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int limit=0;
        int i=0;
        int steps=0;
        int farthest=0;
        while(limit<n-1){
                farthest=max(farthest,i+nums[i]);
                if(limit==i){
                        limit=max(limit,farthest);
                        steps++;
                }
                i++;
        }
            return steps;
    }
};