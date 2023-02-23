class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int> ans;
            unordered_map<int,int> m1;
            int n=nums.size();
            for(int i=0;i<n;i++){
                    int comp=target-nums[i];
                    if(m1.find(comp)!=m1.end()){
                            return {i,m1[comp]};
                    }
                    else{
                            m1[nums[i]]=i;
                    }
            }
            return {};
    }
};