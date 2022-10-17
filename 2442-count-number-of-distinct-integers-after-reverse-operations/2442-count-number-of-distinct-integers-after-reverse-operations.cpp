class Solution {
int ulta(int num){
        vector<int> v1;
        while(num){
                v1.push_back(num%10);
                num/=10;
        }
        int ans=0;
        for(int i=0;i<v1.size();i++){
                ans=ans*10;
                ans+=v1[i];
        }
        return ans;
}
public:
    int countDistinctIntegers(vector<int>& nums) {
        int sz=nums.size();
            unordered_set<int> unique;
            for(int i=0;i<sz;i++){
                    int num=nums[i];
                    int reverse=ulta(num);
                    unique.insert(num);
                    unique.insert(reverse);
            }
            return unique.size();
    }
};