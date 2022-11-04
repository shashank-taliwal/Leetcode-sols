class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
            unordered_map<int,int> hashMap;
            for(int i=0;i<nums.size();i++){
                    int compliment=target-nums[i];
                    if(hashMap.find(compliment)!=hashMap.end()){
                            ans.push_back(hashMap[compliment]);
                            ans.push_back(i);
                    }
                    else{
                            hashMap[nums[i]]=i;
                    }
            }
            return ans;
    }
};