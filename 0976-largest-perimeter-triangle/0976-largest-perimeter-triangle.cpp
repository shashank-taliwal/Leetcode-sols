class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
            int first=0,second=1,third=2;
            int ans=0;
            while(third<n){
                    int first_side=nums[first++];
                    int second_side=nums[second++];
                    int third_side=nums[third++];
                    if(first_side+second_side>third_side){
                            ans=max(ans,first_side+second_side+third_side);
                    }
            }
            return ans;
    }
};