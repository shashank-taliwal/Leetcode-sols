class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
            int n=nums.size();
            int ans=0;
            int diff=INT_MAX;
        for(int i=0;i<n-1;i++){
                int left=i+1,right=n-1;
                while(left<right){
                        int sum=nums[i]+nums[left]+nums[right];
                        if(sum<target){
                                left++;
                        }
                        else if(sum>target){
                                right--;
                        }
                        else{
                                return sum;
                        }
                        if(diff>abs(sum-target)){
                                diff=abs(sum-target);
                                ans=sum;
                        }
                }
        }
            return ans;
    }
};