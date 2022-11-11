class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left=0,right=0,prev=INT_MIN;
        while(right<nums.size()){
            if(prev!=nums[right]){
                nums[left++]=nums[right];
                prev=nums[right];
            }
            right++;
        }
        return left;
    }
};