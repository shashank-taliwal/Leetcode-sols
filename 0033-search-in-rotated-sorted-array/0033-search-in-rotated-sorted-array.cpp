class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Using single binary search
        int n=nums.size();
        int low=0,high=n-1;
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[high]>=nums[mid]){
                //Right half is sorted half
                if(target>=nums[mid] and target<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            else{
                //left half is sorted
                if(target>=nums[low] and target<=nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
        }
        return -1;
    }
};