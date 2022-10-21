class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,vector<int>> m1;
            for(int i=0;i<nums.size();i++){
                    m1[nums[i]].push_back(i);
            }
            for(auto it: m1){
                    for(int i=0;i<(it.second).size()-1;i++){
                            if(it.second[i+1]-it.second[i]<=k){
                                    return true;
                            }
                    }
            }
            return false;
    }
};