class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
            vector<int> ans;
            int special_number=*max_element(nums.begin(),nums.end())+1;
            for(int i=0;i<nums.size();i++){
                    int value=nums[i]%special_number;
                    int idx=value-1;
                    nums[idx]+=special_number;
            }
            for(int i=0;i<nums.size();i++){
                    if(nums[i]/special_number>=2){
                            ans.push_back(i+1);
                    }
            }
            return ans;
    }
        
};