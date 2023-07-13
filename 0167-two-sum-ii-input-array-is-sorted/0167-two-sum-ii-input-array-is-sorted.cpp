class Solution {
    int search(vector<int>& numbers, int target, int index){
        int low=index;
        int high=numbers.size()-1;
        int mid;
        int ans=-1;
        while(low<=high){
            mid=(low+high)/2;
            if(numbers[mid]==target){
                ans=mid;
                low=mid+1;
            }
            else if(numbers[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int n=numbers.size();
        for(int i=0;i<n-1;i++){
            int idx=search(numbers,target-numbers[i],i);
            if(idx!=-1){
                return {i+1,idx+1};
            }
        }
        return {-1,-1};
    }
};