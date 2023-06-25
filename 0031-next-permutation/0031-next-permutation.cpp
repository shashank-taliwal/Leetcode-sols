class Solution {
    int getFirstIndex(vector<int>& nums){
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                return i;
            }
        }
        return -1;
    }
    int getSecondIndex(int ind1, vector<int>& nums){
        int n=nums.size();
        int ans=-1;
        int value=INT_MAX;
        for(int i=n-1;i>ind1;i--){
            if(nums[i]>nums[ind1] and nums[i]<value){
                ans=i;
                value=nums[i];
            }
        }
        return ans;
    }
public:
    void nextPermutation(vector<int>& nums) {
        //Step1 Iterate from back and look for first index such that A[i]<A[i+1]
        //Step2 Mark ith index as ind1
        //Step3 Iterate from back and find the value just greater than A[ind1]
        //Step4 Mark this value as ind2
        //Step5 Swap(A[ind1],A[ind2])
        //Step6 Reverse[A[ind1+1]..............n)
        int ind1=getFirstIndex(nums);
            if(ind1==-1){
            reverse(nums.begin(),nums.end());
                return;
        }
        int ind2=getSecondIndex(ind1,nums);
        // cout<<"99999999";
        swap(nums[ind1],nums[ind2]);
        reverse(nums.begin()+ind1+1,nums.end());
    }
};