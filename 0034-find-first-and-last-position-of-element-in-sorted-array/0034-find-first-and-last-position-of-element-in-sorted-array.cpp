class Solution {
    int getStart(vector<int>& nums, int target){
        int n=nums.size();
        int ans=-1;
        int mid;
        int low=0, high=n-1;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]==target){
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    int getLast(vector<int>& nums, int target){
        int n=nums.size();
        int ans=-1;
        int mid;
        int low=0, high=n-1;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]==target){
                ans=mid;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       int firstPos=getStart(nums,target);
        int lastPos=getLast(nums,target);
        return {firstPos, lastPos};
    }
};