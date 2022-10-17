class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> s1;
            for(int num: nums)s1.insert(num);
            int ans=-1;
            for(int num: nums){
                    if(num>0 and s1.find(-num)!=s1.end()){
                            ans=max(ans,num);
                    }
            }
            return ans;
    }
};