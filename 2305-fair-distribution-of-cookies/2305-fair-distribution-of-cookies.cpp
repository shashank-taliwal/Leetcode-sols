class Solution {
private:
    int util(vector<int>& cookies, vector<int>& distribution, int index, int k){
        //Base case
        if(index==cookies.size()){
            int ans=INT_MIN;
            for(int dis: distribution){
                ans=max(ans,dis);
            }
            return ans;
        }
        int ans=INT_MAX;
        for(int i=0;i<k;i++){
            distribution[i]+=cookies[index];
            ans=min(ans, util(cookies, distribution, index+1, k));
            distribution[i]-=cookies[index];
        }
        return ans;
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> distribution(k,0);
        int ans=util(cookies, distribution, 0, k);
        return ans;
    }
};