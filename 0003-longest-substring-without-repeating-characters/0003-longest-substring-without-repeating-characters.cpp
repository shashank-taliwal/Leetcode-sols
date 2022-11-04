class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m1;
        int n=s.length();
            int ans=0;
            int left=0,right=0;
            for(right;right<n;right++){
                    // cout<<left<<" "<<right<<endl;
                    if(m1.find(s[right])!=m1.end()){
                            left=max(left,m1[s[right]]+1);
                    }
                    m1[s[right]]=right;
                    ans=max(ans,right-left+1);
            }
            return ans;
    }
};