class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(i<=j){
                    if(i==j){
                        dp[i][j]=true;
                    }
                    else if(j-i==1 and s[i]==s[j]){
                        dp[i][j]=true;
                    }
                    else{
                        if(dp[i+1][j-1] and s[i]==s[j]){
                            dp[i][j]=true;
                        }
                    }
                }
            }
        }
        int left=0,right=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j] and j-i>right-left){
                    left=i,right=j;
                }
            }
        }
        string ans;
        for(int i=left;i<=right;i++){
            ans+=s[i];
        }
        return ans;
    }
};