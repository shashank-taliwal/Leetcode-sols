class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> first_occurence;
            int prefix_sum=0;
            for(int i=0;i<nums.size();i++){
                    prefix_sum+=nums[i];
                    int rem=prefix_sum%k;
                    if(first_occurence.find(rem)!=first_occurence.end() and i>first_occurence[rem]+1){
                            return true;
                    }
                    else if(rem==0 and i>0){
                            return true;
                    }
                    else if(first_occurence.find(rem)==first_occurence.end()){
                            first_occurence[rem]=i;
                    }
            }
            return false;
    }
};