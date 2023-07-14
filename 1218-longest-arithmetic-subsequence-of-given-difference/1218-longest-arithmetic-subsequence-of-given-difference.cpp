class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> subs;
        for(int num: arr){
            int x=num-difference;
            if(subs.find(x)!=subs.end()){
                subs[num]=max(subs[num],subs[x]+1);
            }
            else{
                subs[num]=1;
            }
        }
        int ans=-1;
        for(auto it: subs){
            ans=max(ans,it.second);
        }
        return ans;
    }
};