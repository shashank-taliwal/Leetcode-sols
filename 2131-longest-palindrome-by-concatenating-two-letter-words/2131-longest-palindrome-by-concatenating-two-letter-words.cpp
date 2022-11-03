class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        map<string,int> mp;
        for(auto it: words){
            string s = it;
            swap(s[0],s[1]);
            if(mp.find(s) != mp.end()){
               ans += 4;
               mp[s]--; 
               if(mp[s] == 0) mp.erase(s); 
            }
            else{
                mp[it]++;
            }
        }
        for(auto it: mp){
            string r = it.first;
            if(r[0] == r[1]){
                ans += 2;
                break;
            }
        }
        return ans;
    }
};