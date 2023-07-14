class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> subs;
        int ans=-1;
        for(int num: arr){
            int x=num-difference;
            if(subs.find(x)!=subs.end()){
                subs[num]=max(subs[num],subs[x]+1);
            }
            else{
                subs[num]=1;
            }
            ans=max(ans,subs[num]);
        }
        return ans;
    }
};