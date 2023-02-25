class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_index_reach=0;
            int n=nums.size();
            for(int i=0;i<=max_index_reach;i++){
                    max_index_reach=max(max_index_reach,i+nums[i]);
                    if(max_index_reach>=nums.size()-1){
                            return true;
                    }
            }
            return false;
    }
};